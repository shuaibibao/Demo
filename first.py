people={
    'Alice':{
        'phone':'2341',
        'addr':'Foo drive 23'
        
        
        },
    'Beth':{
        'phone':'6789',
        'addr':'Foo drive 99'
        
        
        },
    'Ceil':{
        
        'phone':'2671',
        'addr':'Foo drive 83'
        
        }, 
    }
labels={
    
        'phone':'phone number',
        'addr':'addres'
    }
name=input("Name:")
request=input("phone number(p),addres(a)?")
if request=='p':
    key='phone'
if request=='a':
    key='addr'
if name in people:
    print("%s's %s is %s."%(name,labels[key],people[name][key]))
    





