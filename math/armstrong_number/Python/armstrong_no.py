n = int(input("Enter the number: "))
arm_no = 0
m = n 
while(n!=0):
    r = int(n % 10)
    arm_no = arm_no + (r*r*r)
    n = n / 10
print(arm_no)
if(m == arm_no):
    print(m,"is a armstong number")
else:
    print(m,"is not a armstong number")
