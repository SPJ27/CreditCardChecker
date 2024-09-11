#include <cs50.h>
#include <stdio.h>

int len(long long int n)
{
    int l = 0;
    while (n != 0)
    {
        n /= 10;
        l++;
    }
    return l;
}
int c(long long int number)
{
    int sum = 0;
    int i = 0;
    while (number > 0)
    {
        int digit = number % 10;

        if (i % 2 == 1)
        {
            digit *= 2;
            if (digit >= 10)
            {
                digit -= 9;
            }
        }

        sum += digit;
        number /= 10;
        i++;
    }

    return sum;
}

int main(void)
{
    long long int number = get_long_long("Number: ");
    long long int start = number;
    int l = len(number);
    while (start >= 100)
    {
        start /= 10;
    }

    int checksum = c(number);
    if (checksum % 10 == 0)
    {
        if ((start == 34 || start == 37) && l == 15)
        {
            printf("AMEX\n");
        }
        else if ((start >= 51 && start <= 55) && l == 16)
        {
            printf("MASTERCARD\n");
        }
        else if ((start / 10 == 4) && (l == 16 || l == 13))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
