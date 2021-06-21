print("select Your mode of calculation")
print("1 : simple calculator")
print("2 : scientific calculator")
a = int (input("Enter 1 OR 2 For Your Calculation"))
if(a==1):
    print("1 : Addition")
    print("2 : Subtraction")
    print("3 : Multiplication")
    print("4 : Division")
    b = int(input("Enter your choice of calculation"))
    if(b==1):
        c = int(input("Enter Your 1st No:"))
        d = int(input("Enter Your 2nd No:"))
        e= c+d
        print(e)
    elif(b==2):
        c = int(input("Enter Your 1st No:"))
        d = int(input("Enter Your 2nd No:"))
        e= c-d
        print(e)
    elif(b==3):
        c = int(input("Enter Your 1st No:"))
        d = int(input("Enter Your 2nd No:"))
        e= c*d
        print(e)
    elif(b==4):
        c = int(input("Enter Your 1st No:"))
        d = int(input("Enter Your 2nd No:"))
        e= c/d
        print(e)
elif(a==2):
    import math
    print("1 : sine value(degree)")
    print("2 : cos value(degree)")
    print("3 : tan value(degree)")
    print("4 : cot value(degree)")
    print("5 : square root value of a no:")
    b = int(input("Enter your choice of calculation"))
    if(b==1):
        c = int(input("Enter Your value of degree value in sine:"))
        d=math.sin(c)
        print(d)
    elif(b==2):
        c = int(input("Enter Your value of degree value in cosine:"))
        d=math.cos(c)
        print(d)
    elif(b==3):
        c = int(input("Enter Your value of degree value in tan:"))
        d=math.tan(c)
        print(d)
    elif(b==4):
        c = int(input("Enter Your value of degree value in cot:"))
        d=math.cot(c)
        print(d)
    elif(b==5):
        c = int(input("Enter The number for Square root:"))
        d=math.sqrt(c)
        print(d)


        
    
                
                             
                


        
    
                
                             
                


    
                
                             
                


        
        
    
                
                             
                


        
    
                
                             
                


        
    
                
                             
                
