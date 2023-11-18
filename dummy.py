from mewpy import Animation, AnimationStyle, Counter
import time

#a = Animation(interval=0.3, style=AnimationStyle.Earth)
#a.show()
#time.sleep(10)
#a.done()

c = Counter(interval=0.1, message="Hopping")
c.show()
j = 1
for i in range(20):
    c.work += j
    j += 1
    time.sleep(0.3)
c.done()
