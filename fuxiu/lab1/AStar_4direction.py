import math
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

    def __hash__(self):
        return hash((self.x, self.y))

    def __call__(self):
        return (self.x, self.y)


class AStar:
    def __init__(self, map_obj, start_point, end_point):
        self.map = map_obj
        self.start_point = start_point
        self.end_point = end_point
        self.open_list = []       
        self.closed_list = set()  
        self.path = []
        self.parent = {}

    def get_h(self, point):
        # return 10 * (abs(point.x - self.end_point.x) + abs(point.y - self.end_point.y))
        return 10 * math.sqrt((point.x - self.end_point.x)**2 + (point.y - self.end_point.y)**2)

    def get_g(self, current, neighbor):
        dx = abs(current.x - neighbor.x)
        dy = abs(current.y - neighbor.y)
        return 10 if dx == 0 or dy == 0 else 14

    def get_neighbors(self, current_point):
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1),
                (-1, -1), (-1, 1), (1, -1), (1, 1)]
        neighbors = []
        for dx, dy in dirs:
            nx, ny = current_point.x + dx, current_point.y + dy
            n_p = Point(nx, ny)
            if self.map.isPass(n_p):
                neighbors.append(n_p)
        return neighbors

    def final_path(self, end_point):
        path = []
        current = end_point
        while current in self.parent:
            path.append(current)
            current = self.parent[current]
        path.append(self.start_point)
        path.reverse()
        self.path = path

    def start(self):
        self.open_list.append((self.start_point, 0))
        self.parent[self.start_point] = None

        while self.open_list:
            self.open_list.sort(key=lambda x: x[1] + self.get_h(x[0]))
            current_point, current_g = self.open_list.pop(0)

            if current_point == self.end_point:
                self.final_path(current_point)
                return True

            self.closed_list.add(current_point)

            for neighbor in self.get_neighbors(current_point):
                if neighbor in self.closed_list:
                    continue

                g_cost = current_g + self.get_g(current_point, neighbor)
                in_open = next((item for item in self.open_list if item[0] == neighbor), None)

                if not in_open:
                    self.open_list.append((neighbor, g_cost))
                    self.parent[neighbor] = current_point
                else:
                    if g_cost < in_open[1]:
                        self.open_list.remove(in_open)
                        self.open_list.append((neighbor, g_cost))
                        self.parent[neighbor] = current_point

        return False

    def setMap(self):
        for p in self.path:
            self.map.setMap(p)
