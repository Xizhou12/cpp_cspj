x = input("Enter numbers: ")
x = [int(i) for i in x.split(" ")]
print("输入的数组 ",x)
for i in range(len(x)):
  x[i] = 5
print("全部改成5: ", x)