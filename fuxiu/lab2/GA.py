import numpy as np
import matplotlib.pyplot as plt

x_min, x_max = -10.0, 10
y_min, y_max = -10.0, 10

def f(x, y):
    return (83*(x**4) - 16*(x**2) + 5*x + y**4 - 16*(y**2) + 5*y) / 2.0

def random_init():
    x = np.random.uniform(x_min, x_max)
    y = np.random.uniform(y_min, y_max)
    return np.array([x, y], dtype=float)

def evaluate(pop):
    xs = pop[:, 0]
    ys = pop[:, 1]
    return f(xs, ys)

def select(pop, fitness, k=3):
    idxs = np.random.choice(len(pop), size=k, replace=False)
    best_idx = idxs[np.argmin(fitness[idxs])]
    return pop[best_idx].copy() 

def crossover(parent1, parent2, alpha=0.5):
    child = np.empty_like(parent1)
    for i in range(len(parent1)):
        d = abs(parent1[i] - parent2[i])
        low = min(parent1[i], parent2[i]) - alpha * d
        high = max(parent1[i], parent2[i]) + alpha * d
        child[i] = np.random.uniform(low, high)
    return child

def mutate(individual, mutation_prob=0.3, mutation_std=0.5):
    if np.random.rand() < mutation_prob:
        individual = individual.copy()
        individual += np.random.normal(0, mutation_std, size=individual.shape)
        individual[0] = np.clip(individual[0], x_min, x_max)
        individual[1] = np.clip(individual[1], y_min, y_max)
    return individual

def main():
    POP_SIZE = 100
    N_GENERATIONS = 100
    TOURNAMENT_K = 3
    MUTATION_PROB = 0.3
    MUTATION_STD = 0.5
    BLX_ALPHA = 0.5

    np.random.seed(42)

    population = np.array([random_init() for _ in range(POP_SIZE)])
    # 记录每代最优值
    best_history = []

    for gen in range(N_GENERATIONS):
        fitness = evaluate(population)
        new_population = []

        while len(new_population) < POP_SIZE:
            parent1 = select(population, fitness, k=TOURNAMENT_K)
            parent2 = select(population, fitness, k=TOURNAMENT_K)
            child = crossover(parent1, parent2, alpha=BLX_ALPHA)
            child = mutate(child, mutation_prob=MUTATION_PROB, mutation_std=MUTATION_STD)
            new_population.append(child)

        population = np.array(new_population)

        best_fitness = np.min(fitness)
        avg_fitness = np.mean(fitness)
        best_history.append(best_fitness)
        print(f"代数 {gen+1}: 最佳 = {best_fitness:.4f}, 均值 = {avg_fitness:.4f}")

    final_fitness = evaluate(population)
    best_idx = np.argmin(final_fitness)
    best_individual = population[best_idx]
    best_value = final_fitness[best_idx]
    print(f"final ans: x = {best_individual[0]:.4f}, y = {best_individual[1]:.4f}, f(x,y) = {best_value:.4f}")

    gens = list(range(1, len(best_history) + 1))
    plt.figure(figsize=(8, 4))
    plt.plot(gens, best_history, '-o', markersize=3)
    plt.xlabel('Generation')
    plt.ylabel('Best fitness')
    plt.title('GA Best Fitness per Generation')
    plt.grid(True)
    plt.tight_layout()
    plt.show()


if __name__ == "__main__":
    main()
