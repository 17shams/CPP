#include <iostream>

void readMarks(int *marks, std::size_t N);
double average(const int *marks, std::size_t N);
void bumpLowest(int &mark);
void printMarks(const int *marks, std::size_t N);

int main()
{
    constexpr std::size_t N = 5;
    int marks[N];

    std::cout << "Enter 5 marks: ";
    readMarks(marks, N);

    // index
    std::cout << "Marks (index):   ";
    for (std::size_t i = 0; i < N; ++i)
        std::cout << marks[i] << ' ';

    std::cout << '\n';

    // pointer
    std::cout << "Marks (pointer):   ";
    for (std::size_t i = 0; i < N; ++i)
        std::cout << *(marks + i) << ' ';

    std::cout << '\n';

    std::cout << "Average before bump: " << average(marks, N) << '\n';

    // lowest mark
    std::size_t lowestMark = 0;
    for (std::size_t i = 0; i < N; ++i)
        if (marks[i] < marks[lowestMark])
        {
            lowestMark = i;
        }

    int markBefore = marks[lowestMark];
    bumpLowest(marks[lowestMark]);

    std::cout << "Lowest mark was " << markBefore
              << " -> bumped to " << marks[lowestMark] << '\n';

    std::cout << "Average after bump:  " << average(marks, N) << std::endl;

    int *maybeNothing = nullptr;
    if (maybeNothing != nullptr)

        return 0;
}

void readMarks(int *marks, std::size_t N)
{
    for (std::size_t i = 0; i < N; i++)
    {
        std::cin >> marks[i];
    }
}

double average(const int *marks, std::size_t N)
{
    double sum = 0;

    for (std::size_t i = 0; i < N; ++i)
        sum += marks[i];

    return sum / N;
}

void bumpLowest(int &mark)
{
    mark += 2;
}

void printMarks(const int *marks, std::size_t N)
{
    for (int i = 0; i < N; ++i)
        std::cout << marks[i] << ' ';
    std::cout << '\n';
}
