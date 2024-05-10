class Solution:
  def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
    # Use a list of tuples for fractions (value, (numerator, denominator))
    fractions = []

    n = len(arr)
    for i in range(n):
      for j in range(i + 1, n):
        # Calculate fraction as float
        fraction = arr[i] / arr[j]
        fractions.append((fraction, (arr[i], arr[j])))

    # Sort fractions by value (ascending order) with lambda function
    fractions.sort(key=lambda x: x[0])

    # Access kth smallest fraction (0-indexed) and return numerator/denominator
    return [fractions[k - 1][1][0], fractions[k - 1][1][1]]
