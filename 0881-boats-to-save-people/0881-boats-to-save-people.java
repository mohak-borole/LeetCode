class Solution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int x = 0;
        int l = 0, r = people.length - 1;
        while (l <= r) {
            x++;
            if (people[l] <= limit - people[r])
                l++;
            r--;
        }
        return x;
    }
}