import pylab as pl

def h(t):
    return 1.2743 * pl.sin(2*t) + 0.4244 * pl.sin(6*t) + 0.25465 * pl.sin(10*t) + 0.18189 * pl.sin(14*t) + 0.14147 * pl.sin(18*t)
def dh(t):
    return 2.5486 * pl.cos(2*t) + 2.5464 * pl.cos(6*t) + 2.5465 * pl.cos(10*t) + 2.54646 * pl.cos(14*t) + 2.54646 * pl.cos(18*t)

a, b, n = -pl.pi, pl.pi, 20000
dx = (b-a)/(n-1)

xs = [a + i * dx for i in range(n)]
ys1 = [h(t) for t in xs]
ys2 = [dh(t) for t in xs]

pl.plot(xs, ys1)
pl.plot(xs, ys2)

pl.grid()
pl.xlabel("X")
pl.ylabel("Y")

pl.show

