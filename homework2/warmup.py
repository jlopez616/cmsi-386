import math
import re
import requests

def change (amount):
        if amount < 0:
            raise ValueError('amount cannot be negative')
        else:
            remaining = amount;
            quarters =  math.floor(remaining / 25);
            remaining %= 25;
            dimes = math.floor(remaining / 10)
            remaining %= 10
            nickels = math.floor(remaining / 5)
            remaining %= 5;
            pennies = remaining;
            return (quarters, dimes, nickels, pennies)

def strip_quotes (string):
    return re.sub(r"['\"]", "", string)


def interleave(array, *data):

    firstLength = len(array)
    secondLength = len(data)
    result = []
    otherValues = list(data)
    maximum = max(firstLength, secondLength)
    for each in range(maximum):
         if (each < firstLength):
             result.append(array[each])
         if (each < secondLength):
             result.append(otherValues[each]);
    return result

def say(firstWord = None):
    words = []
    def sayMore(word = None):
        if word is None:
            return " ".join(words)
        words.append(word)
        return sayMore
    return sayMore(firstWord)

def random_name(**data):
    filter = {'gender': data['gender'], 'region': data['region']}
    response = requests.get("http://api.uinames.com", params=filter)
    name = response.json()
    if 'name' in name:
        print ("key")
        return name['surname'] + ", " + name['name']
    else:
        print ("also key")
        print (name['error'])
        raise ValueError("error:" + name['error'])
