# Print the cube of odd numbers and the number itself if even, for numbers from 0 to 19
for num in range(20):
    if num % 2 != 0:
        cube = num**3
    else:
        cube = num
    print(cube)

