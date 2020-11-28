import numpy

#This function will return the maximum and minimum value from an array
def maxAndMin(x):
    ma  = numpy.max(x)
    mi = numpy.min(x)
    return ma, mi

#This function will return the average of the values in an array
def calculateAvg(x):
    avg = numpy.mean(x)
    return avg

if __name__ == "__main__":
    someNumbers = [3, 23, 5, 32, 6, 4, 7, 2, 54, 1, 3, 8, 3, 5, 6, 8, 1, 3, 6, 9, 3, 5, 2]
    biggest, smallest = maxAndMin(someNumbers)
    #Please add a call to calculateAvg and store the return in a variable called avg
    print("Max value: ", biggest)
    print("Min value: ", smallest)
    print("Average value: ", avg)
