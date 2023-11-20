from mewpy import Animation, AnimationStyle, Counter, Speed, DType, ProgressBar
import time

a = Animation(interval=0.3, style=AnimationStyle.Earth)
a.show()
time.sleep(10)
a.done()

def start(dtype: DType):
    return 1 if dtype in [DType.Int, DType.AtomicInt] else 0.7

def increment(dtype: DType):
    return 1 if dtype in [DType.Int, DType.AtomicInt] else 0.33

for dtype in [DType.Int, DType.Float, DType.AtomicInt, DType.AtomicFloat]:
    for speed in [Speed.No, Speed.Overall]:
        c = Counter(interval=0.1, message="Hopping", speed=speed, speed_unit="hop/s", dtype=dtype)
        c.show()
        j = start(dtype) 
        for i in range(20):
            c += j
            j += increment(dtype)
            time.sleep(0.3)
        c.done()


c.work = 0.2
c.show()
c.done()

c += 0.1
c.show()
c.done()

for dtype in [DType.Int, DType.Float, DType.AtomicInt, DType.AtomicFloat]:
    for speed in [Speed.No, Speed.Overall]:
        b = ProgressBar(interval=0.1, message="Loading", speed=speed, speed_unit="B/s", dtype=dtype)
        b.show()
        for i in range(100):
            b += 1
            time.sleep(0.12)
        b.done()