import numpy as np
import pandas as pd
from sklearn import linear_model
from matplotlib import pyplot as plt

data = pd.read_csv('ML_HW/data.csv')
x = data[['x']]
y = data[['y']]
model = linear_model.LinearRegression()
model.fit(x, y)
pred = model.predict(x)

plt.scatter(x, y, color='blue', label='data')
plt.plot(x, pred, color='red', label='linear')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Linear model')
plt.legend()
plt.show()
