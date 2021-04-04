#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int number)
{
    if (number < 2)
        return false;
    for (int div = 2; div < number / div + 1; ++div)
        if (number % div == 0)
            return false;
    return true;
}

void recursive(int remainingDigits, int number, vector<int> numbers, vector<int> &primeNumbers)
{
    if (remainingDigits == 0)
    {
        if (isPrime(number))
            primeNumbers.push_back(number);
        return;
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        vector<int> temp(numbers);
        temp.erase(temp.begin() + i);
        recursive(remainingDigits - 1, number * 10 + numbers[i], temp, primeNumbers);
    }
}

int solution(string numbers)
{
    vector<int> primeNumbers;
    vector<int> numbersToVector;

    for (int i = 0; i < numbers.size(); ++i)
        numbersToVector.push_back(numbers[i] - '0');

    for (int digits = numbers.size(); digits > 0; digits--)
        recursive(digits, 0, numbersToVector, primeNumbers);

    sort(primeNumbers.begin(), primeNumbers.end());
    primeNumbers.erase(unique(primeNumbers.begin(), primeNumbers.end()), primeNumbers.end());

    return primeNumbers.size();
}
