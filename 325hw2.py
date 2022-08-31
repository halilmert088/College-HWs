#Halil Mert CEYLAN, 18243510049
#CMPE325 HW2


def final_credit(i):
    switcher = {
        "AA" : 4.00,
        "BA" : 3.50,
        "BB" : 3.00,
        "CB" : 2.50,
        "CC" : 2.00,
        "DC" : 1.50,
        "DD" : 1.00,
        "FD" : 0.50,
        "FF" : 0.00,
        }
    return switcher.get(i, "Invalid grade")


stu = {}
stu = dict()
honor = []
ch = 'Y'

while (ch == 'Y' or ch == 'y') and (ch != 'N' or ch != 'n'):
    ct = 0
    lessons = {}
    lessons = dict()
    
    stu_id = int(input("Enter student id: "))
    class_no = int(input("Enter number of courses registered: "))
    
    while ct < class_no:
        inp = input("Enter course name, ECTS, grade: ")
        myTuple = (float(inp.split(", ")[1]), inp.split(", ")[2]) 
        lessons[inp.split(", ")[0]] = myTuple
        ct = ct + 1
    
    stu[stu_id] = lessons

    ch = input("Do you want to continue Y/N?: ")
    print("\n")
print("\n")

for i in stu:
    creds = 0
    ects = 0.0
    avg = 0.0

    j = stu.get(i)
    
    for str in j:
        l = j.get(str)[0]
        creds = creds + l
        k = j.get(str)[1]
        ects = ects + (l * final_credit(k))
 
    avg = ects / creds

    if avg >= 3.00:
        honor.append(i)

    print("Student id: ", i, "   GPA: ", "{:.2f}".format(avg))


if len(honor) != 0:
    print("\nHonor Students with GPA above 3.0")
    i = 0
    while i < len(honor):
        print(honor[i])
        i = i + 1

