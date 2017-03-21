class Rectangle:
    def __init__(self):
        self.width=0
        self.height=0
    def setSize(self,size):
        self.width,self.height=size
    def getSize(self):
        return self.width,self.height
r=Rectangle()
r.width=10
r.height=5
print(r.getSize())
r.setSize((150,100))
print(r.width)




#使用新类的property属性
__metaclass__=type
class Rectangle:
    def __init__(self):
        self.width=0
        self.height=0
    def setSize(self,size):
        self.width,self.height=size
    def getSize(self):
        return self.width,self.height
    size=property(getSize,setSize)
r=Rectangle()
r.width=10
r.height=5
print(r.getSize())
r.setSize((150,100))
print(r.width)
print(r.size)





__metaclass__=type
class Myclass:
    def smeth():
        print("this is a static method")
    smeth=staticmethod(smeth)
    def cmeth(cls):
        print("this is a class method of",cls)
    cmeth=classmethod(cmeth)
Myclass.smeth()
Myclass.cmeth()



class Fibs:
    def __init__(self):
        self.a=0
        self.b=1
    def __next__(self):
        self.a,self.b=self.b,self.a+self.b
        return self.a
    def __iter__(self):
        return self
fibs=Fibs()
for f in fibs:
    if f>1000:
        print(f)
        break
it=iter([1,2,3])
print(next(it))
print(next(it))   



class TestIterator:
    value=0
    def __next__(self):
        self.value+=1
        if self.value>10:raise StopIteration
        return self.value
    def __iter__(self):
        return self 
ti=TestIterator()
print(ti)
print(list(ti))       




def flatten(nest):
    for sublist in nest:
        for element in sublist:
            yield element
nested=[[1,2],[3,4],[5]]
for num in flatten(nested):
    print(num)
g=((i+2)**2 for i in range(2,27))
print(next(g))
print(sum(i**2 for i in range(10)))
        





def flatten(nest):
    try:
        try:nest+""
        except TypeError:pass
        else: raise TypeError
        for sublist in nest:
            for element in flatten(sublist):
                yield element
    except TypeError:
        yield nest
s=list(flatten([[[1],2],3,4,[5,[6,7]],8]))
print(s)
m=list(flatten(['foo',['bar',['baz']]]))
print(m)  








def repeater(value):
    while True:
        new=(yield value)
        if new is not None:value=new
r=repeater(42)
print(next(r))
print(next(r))
print(r.send('hello'))
print(next(r))





def flatten(nested):
    result=[]
    try:
        try:nested+""
        except TypeError:pass
        else:raise TypeError
        for sublist in nested:
            for element in flatten(sublist):
                result.append(element)
    except TypeError:
        result.append(nested)
    return result
list=[1,[2,3],4]
print(flatten(list))
list="abcd"
print(flatten(list))


        

            
            
                  