/*
 * Course: COEN 2220 - Programming 2
 * Name: [Sebastian Ortiz]
 * Lab: Lab 8 - Big-O / Time Complexity
 * Description: Resolved code for time-complexity analysis
 * Due date: [10/12/2026]
 */

#include <iostream>
using namespace std;

/* Returns the ID stored at a valid position already known by the caller. */
int getActivityIdAt(const int activityIds[], int activityIndex)
{
    return activityIds[activityIndex]; // Read one known array position.
}

/* Returns how many activities have an active status. */
int countActiveActivities(const bool isActive[], int activityCount)
{
    int activeCount = 0;

    for (int index = 0; index < activityCount; index++)
    {
        if (isActive[index])
        {
            activeCount++;
        }
    }

    return activeCount;
}

/*
 * Returns how many middle IDs binary search compares before finding targetId.
 * Precondition: activityIds is sorted in ascending order and contains targetId.
 */
int countBinaryComparisons(const int activityIds[], int activityCount, int targetId)
{
    int first = 0;
    int last = activityCount - 1;
    int comparisons = 0;

    while (first <= last)
    {
        int middle = (first + last) / 2;
        comparisons++;

        if (activityIds[middle] == targetId)
        {
            break;
        }
        else if (activityIds[middle] < targetId)
        {
            first = middle + 1;
        }
        else
        {
            last = middle - 1;
        }
    }

    return comparisons;
}

/* Returns how many times a positive count can be reduced by half before reaching 1. */
int countHalvingSteps(int itemCount)
{
    int steps = 0;

    while (itemCount > 1)
    {
        itemCount = itemCount / 2; // Remove approximately half of the remaining items.
        steps++;
    }

    return steps;
}

/* Returns the number of distinct activity pairs visited by two nested loops. */
int countPossiblePairs(int activityCount)
{
    int pairCount = 0;

    for (int first = 0; first < activityCount; first++)
    {
        for (int second = first + 1; second < activityCount; second++)
        {
            pairCount++; // One distinct pair would be compared here.
        }
    }

    return pairCount;
}

int main()
{
    // These activity IDs are sorted so binary search is valid.
    int activityIds[] = {101, 104, 108, 115, 130, 136, 140, 155};
    bool isActive[] = {true, false, true, true, false, false, true, false};
    int activityCount = 8;

    cout << "Activity at index 2: "
         << getActivityIdAt(activityIds, 2) << endl;
    cout << "Active activities: "
         << countActiveActivities(isActive, activityCount) << endl;
    cout << "Binary comparisons for 140: "
         << countBinaryComparisons(activityIds, activityCount, 140) << endl;
    cout << "Halving steps for 8: " << countHalvingSteps(8) << endl;
    cout << "Halving steps for 16: " << countHalvingSteps(16) << endl;
    cout << "Halving steps for 32: " << countHalvingSteps(32) << endl;
    cout << "Possible pairs for 4 activities: " << countPossiblePairs(4) << endl;
    cout << "Possible pairs for 8 activities: " << countPossiblePairs(8) << endl;

    return 0;
}

/*
 * Analysis Answers
 *
 * C1 — Direct access
 * Answer: N in this case is use to access a single element in an array. It represents a space in the memory where the element is stored. The clasification of this function is O(1) because it takes a constant time to access an element and there is no dependence on size of the array..
 *
 * C2 — Count active activities
 * Answer: N in this case is the number of activities. The function iterates through the array once with the purpuse of checking every activity status. Therefore, the classification is O(N) because the time taken is directly proportional to the number of activities.
 *
 * C3 — Binary search
 * Answer: N in this case is the number of activities(activityCount). The function compares the middle element with the target value. Therefore, the classification is O(log N) because the time taken is proportional to the logarithm of the number of activities.
 *
 * C4 — Halving steps
 * Answer: N in this case is the number of items(itemCount). The function repeatedly divides the count by 2 until it reaches 1. Therefore, the classification is O(log N) because the time taken is proportional to the logarithm of the number of items.  
 *
 * C5 — Distinct pairs
 * Answer: N in this case is the number of activities(activityCount). The function uses two for loops to count distinct pairs. It uses in the first loop "first < activityCount" and in the second loop "second < activityCount" ("int second" is "first + 1") for counting just the distinct pairs, not repeated ones . Therefore, the classification is O(N^2) because the time taken is proportional to the square of the number of activities.
 *
 * C6 — Compare the observed patterns
 * Answer: The observed patterns show that the time complexity of each function changes based on the operations performed. For example:
 * In direct access, the time complexity is O(1) because it takes constant time to access an element:
 * getActivityIdAt(activityIds, 2) returns 108.
 * As a result, the funtion is O(1) because it shows that its just a single operation to access an element in the array.
 * Anorher example is the countActiveActivities function, which has a time complexity of O(N) because it iterates through the entire array to count active activities:
 * countActiveActivities(isActive, activityCount) returns 4.
 * Binary search has a time complexity of O(log N) because it divides the search space in half with each comparison:
 * countBinaryComparisons(activityIds, activityCount, 140) returns 3. 
 * Halving steps also has a time complexity of O(log N) because it repeatedly divides the count by 2 until it reaches 1:
 * countHalvingSteps(8) returns 3.
 * When the value doubles, the number of halving steps increases by 1, which is consistent with logarithmic growth.
 * Finally, the countPossiblePairs function has a time complexity of O(N^2) because it uses two loops to count distinct pairs:
 * countPossiblePairs(4) returns 6.
 * The output shows that the number of distinct pairs increases quadratically with the number of activities, which is consistent with the O(N^2) classification.
 * 
 * C7 — Sorting decision
 * Answer: If the Ids were not sorted and you only need to do a slingle search, a linear search would be more efficient than a binary search. This is because a linear search has a time complexity of O(N), while a binary search has a time complexity of O(log N). In the case of an unsorted array, a linear search would be the best option for finding an element, as it does not require the array to be sorted and can find the target element in a single pass through the array.
 * In the other hand, if you need to do multiple searches, it would be more efficient to sort the array first and then use binary search for the following searches. This is because sorting the array has a time complexity of O(N log N), but once sorted, each binary search can be performed in O(log N) time. Therefore, if you have multiple searches to perform, binary is more efficient overall.
 * 
 */