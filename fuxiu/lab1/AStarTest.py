from map2d import map2d
from AStar_4direction import *
from time import time

if __name__ == '__main__':
    ##构建地图
    mapTest = map2d()
    mapTest.showMap()
    ##构建A*
    aStar = AStar(mapTest, Point(1,1), Point(8,18))

    print ("A* start:")
    ##开始寻路
    time0 = time()  # 修复：调用 time() 方法
    if aStar.start():
        aStar.setMap()
        timenow = time()  # 修复：调用 time() 方法
        mapTest.showMap()
        dt = timenow - time0
        print(f"cost {dt:.6f} s")  # 格式化输出时间
    else:
        print ("no way")
