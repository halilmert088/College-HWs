def switch_demo(i):
    switcher = {
        "AA" : 4.00,
        "AB" : 3.50,
        "BA" : 3.50,
        "BB" : 3.00,
        "BC" : 2.50,
        "CB" : 2.50,
        "CC" : 2.00,
        "CD" : 1.50,
        "DC" : 1.50,
        "DD" : 1.00,
        "DF" : 0.50,
        "FD" : 0.50,
        "FF" : 0.00,
        }
    return switcher.get(i, "Invalid grade")

k = switch_demo("AA")
print(k)
z = 6
k = switch_demo("CC") * z
print(k)