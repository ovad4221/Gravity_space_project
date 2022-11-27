import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

df = pd.read_csv('rc.csv')
del df['Unnamed: 13']

x = lambda x0, v0, a, t: x0 + v0 * t + a * t**2 / 2
time = np.arange(0, 30, 0.01)
x_1 = [x(0, 20, 0, t) for t in time]
y_1 = [x(0, 100, -10, t) for t in time]
x_2 = [x(0, 10, 0, t) for t in time]
y_2 = [x(0, 60, -10, t) for t in time]

plt.figure(figsize=(8, 6), facecolor='#aaaaaa')

ax = plt.axes()
ax.set_facecolor('#353535')
ax.minorticks_on()

ax.grid(which='major', ls='--', color=(0.5, 0.5, 0.5, 0.1))
ax.grid(which='minor', color=(0.5, 0.5, 0.5, 0.1), linestyle=':')

plt.rcdefaults()

plt.plot(x_1, y_1, label=f'$1\ true$')
plt.plot(x_2, y_2, label=f'$2\ true$')
plt.scatter(df.x1, df.y1, label=f'$runge-cutta1$')
plt.scatter(df.x2, df.y2, label=f'$runge-cutta2$')

plt.title(r'$Тестовый\ график\ работы\ метода\ Рунге-Кутты\ 4$', fontsize=15)

plt.ylabel(r'$y,m$', fontsize=15)
plt.xlabel(r'$x,m$', fontsize=15)

plt.legend(loc='lower right', fontsize=14)

plt.show()
