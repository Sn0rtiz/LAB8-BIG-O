# Lab 8 — Part D Pseudocode Analysis

## D1 — Search and scan pseudocode
**Answer: n represents the number of activities (IDs) on the list. Binery search is used to compare the middle ID with the target ID and discard half of the ramaining IDs each time. The for loop is used to check every activity's "is Active" value once, so it takes O(n)time. For binary search the operation being counted is the comeparison of "sortedIds[middle]" and "targetId". For the scan, it counts each check of "IsActive[index]". Both sections run one after the other and their cost are added together. That said, the linear scan grows faster and dominates the total, so you can simplified the result to O(n). They aren't multiply automaticly because of the search loop and the scan loop are not nested inside of one another.**

## D2 — Potential-conflict pseudocode
**Answer: n represents the number of activities that are being checked(count). The variable "second" is equeled to "first + 1" to avoid the comparison of the same activity or cheking the same pair two times. When "count" doubles its value the number of comparisons grows about four times, this is shown in the example from appointment_analysis_example.cpp by the results for 50, 100, and 200 activities. The oparation used here is an O(n^2) time complexity.**
