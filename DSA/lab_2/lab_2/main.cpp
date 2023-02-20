//
//  main.cpp
//  lab_2
//
//  Created by Nastya Bekesheva on 20.02.2023.
//

#include <iostream>
#include <chrono>
#include <string>

int M = 0;
int C = 0;

void swap(int & a, int & b)
{
    M++;
    int temp;
    temp = a;
    a = b;
    b = temp;
}

bool lessThan(int a, int b)
{
    C++;
    return (a < b);
}

bool lessThanOrEqualTo(int a, int b)
{
    C++;
    return (a <= b);
}

void selectionSort(int* array, int size)
{
    M = C = 0; //  count of moves and compares
    int min;
    for(int i = 0; i < size-1; i++) //  loop through array
    {
        min = i; //  set min to element i
        for(int j = i+1; j < size; j++)
        {
            if(lessThan(array[j], array[min]))
            {
                min = j; //  find index of actual min element
            }
        }
        swap(array[min], array[i]); //  swap min and first (unsorted part of array) element
    }
  
}

void shellSort(int* array, int size)
{
    M = C = 0; //  count of moves and compares
    int knuth_interval = 1;
    while (knuth_interval < size/3)
    {
        knuth_interval = knuth_interval * 3 + 1; //  find initial interval with Knuth's formula h_(k-1)=3h_k+1
    }
    while (knuth_interval > 0)
    {
        for (int i = knuth_interval; i < size; i++) //  loop through interval
        {
            int insertion_value = array[i]; //  initialize value that's gonna be inserted later
            int j = i; //  index of current element
            C++;
            while ((j > knuth_interval-1) && array[j-knuth_interval] >= insertion_value) //  compare
            {
                M++;
                array[j] = array[j-knuth_interval]; //  move element
                j = j - knuth_interval; //  change index
            }
            M++;
            array[j] = insertion_value; //  move element that's marked as 'to be inserted'
        }
        knuth_interval = (knuth_interval-1) / 3; //  change interval
    }
}
/* bad shell sort
void shellSort2(int* array, int size)
{
    M = C = 0;
    int i, j, k;
    for (i = size/2; i > 0; i = i/2)
    {
        for (j = i; j < size; j++)
        {
            for (k = j - i; k >= 0; k = k - i){
                if(lessThanOrEqualTo(array[k+i], array[k])){
                    swap(array[k], array[k+i]);
                }
            }
        }
    }
}*/

void print(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

void generateArray(int* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        array[i] = rand() % 100;
    }
}

void efficiencyTest(int sort_choice, bool print_choice, int size)
{
    std::cout << std::endl;
    int array[size];
    generateArray(array, size);
    if (sort_choice == 1)
    {
        if (print_choice)
        {
            std::cout << "Before selection sort:" << std::endl;
            print(array, size);
        }
        auto start = std::chrono::high_resolution_clock::now();
        selectionSort(array, size);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Time taken by selection sort: "
                 << duration.count() << " microseconds" << std::endl;
        if (print_choice)
        {
            std::cout << "After selection sort:" << std::endl;
            print(array, size);
        }
        std ::cout << "Amout of moves: " << M << std::endl;
        std ::cout << "Amout of compares: " << C << std::endl;
    }
    else if (sort_choice == 2)
    {
        if (print_choice)
        {
            std::cout << "Before shell sort:" << std::endl;
            print(array, size);
        }
        auto start = std::chrono::high_resolution_clock::now();
        shellSort(array, size);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Time taken by shell sort: "
                 << duration.count() << " microseconds" << std::endl;
        if (print_choice)
        {
            std::cout << "After shell sort:" << std::endl;
            print(array, size);
        }
        std ::cout << "Amout of moves: " << M << std::endl;
        std ::cout << "Amout of compares: " << C << std::endl;
    }
    std::cout << std::endl;
}

bool isNumber(const std::string &s) {
  return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    bool action = true;
    while (action)
    {
        std::cout << "Enter key to procede:\n 1. Selection sort\n 2. Shell sort\n 3. Exit\n";
        std::string key;
        std::cin >> key;
        if (isNumber(key) == true)
        {
            int newKey = stoi(key);
            switch (newKey)
            {
                case 1:
                {
                    std::cout << "Starting selection sort...\nEnter size of array:\n";
                    std::string a;
                    std::cin >> a;
                                        
                    if (isNumber(a) == true)
                    {
                        std::cout << "Would you like to print array?\n (1 - yes, 0 - no)" << std::endl;
                        std::string b;
                        std::cin >> b;
                        if (isNumber(b) == true)
                        {
                            bool c;
                            if (stoi(b) == 1) c = true;
                            else if (stoi(b) == 0) c = false;
                            else
                            {
                                std::cout << "Invalid input" << std::endl;
                                break;
                            }
                            efficiencyTest(1, c, stoi(a));
                        }
                        else
                        {
                            std::cout << "Invalid input" << std::endl;
                            break;
                        }
                        break;
                    }
                    else
                    {
                        std::cout << "Invalid input" << std::endl;
                        break;
                    }
                }
                case 2:
                {
                    std::cout << "Starting shell sort...\nEnter size of array:\n";
                    std::string a;
                    std::cin >> a;
                                        
                    if (isNumber(a) == true)
                    {
                        std::cout << "Would you like to print array?\n (1 - yes, 0 - no)" << std::endl;
                        std::string b;
                        std::cin >> b;
                        if (isNumber(b) == true)
                        {
                            bool c;
                            if (stoi(b) == 1) c = true;
                            else if (stoi(b) == 0) c = false;
                            else
                            {
                                std::cout << "Invalid input" << std::endl;
                                break;
                            }
                            efficiencyTest(2, c, stoi(a));
                        }
                        else
                        {
                            std::cout << "Invalid input" << std::endl;
                            break;
                        }
                        break;
                    }
                    else
                    {
                        std::cout << "Invalid input" << std::endl;
                        break;
                    }
                }
                case 3:
                {
                    action = false;
                    std::cout << "Bye!" << std::endl;
                    break;
                }
                    
                    
                default:
                    break;
            }
        }
        else { std::cout << "Invalid input" << std::endl; }
    }
    return 0;
}
