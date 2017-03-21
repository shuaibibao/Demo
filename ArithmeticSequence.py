def checkIndex(key):
    if not isinstance(key, int):raise TypeError
    if key<0:raise IndexError
class ArithmeticSequece:
    def __init__(self,start=0,step=1):
        self.start=start
        self.step=step
        self.changed={}
    def __getitem__(self,key):
        checkIndex(key)
        try:return self.changed[key]
        except KeyError:
            return self.start+self.step*key
    def __setitem__(self,key,value):
        checkIndex(key)
        self.changed[key]=value
s=ArithmeticSequece(1,2)
print(s[4])
s[4]=2
print(s[4])#使用前后双下划线实现简单序列

