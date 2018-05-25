#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>

#include <algorithm>
#include <cstring>
#include <climits>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class MaxInnerRec
{
  public:
    int countArea(vector<int> A, int n)
    {
        // write code here
        if (n == 0)
            return 0;
        int global = A[0];
        int local = A[0];

        int minNum = A[0];
        int minIndex = 0;
        // cout << "local " << local
        //      << " global " << global
        //      << " minNum " << minNum
        //      << " minIndex " << minIndex << endl;

        for (int i = 1; i < n; i++)
        {
            // cout << "local " << local
            //      << " global " << global
            //      << " minNum " << minNum
            //      << " minIndex " << minIndex << endl;
            int tmp = 0;

            if (A[i] < minNum)
            {
                tmp = A[i] * (local / minNum + 1);
                // minNum = A[i];
                // minIndex = i;
            }
            else
            {
                tmp = local + minNum;
            }

            if (A[i] >= tmp)
            {
                minNum = A[i];
                minIndex = i;
            }
            else if (A[i] <= minNum)
            {
                minNum = A[i];
                minIndex = i;
            }
            local = max(A[i], tmp);
            // cout << local << endl;
            global = max(local, global);
            // cout << global << endl;
        }

        return global;
    }
};

int main()
{
    {
        MaxInnerRec a;
        vector<int> nums = {2, 7, 9, 4, 1};
        cout << a.countArea(nums, nums.size()) << endl;
    }
    cout << "------------\n";
    {
        MaxInnerRec a;
        vector<int> nums = {9, 7, 4, 2, 1};
        cout << a.countArea(nums, nums.size()) << endl;
    }
    cout << "------------\n";

    {
        MaxInnerRec a;
        vector<int> nums = {281, 179, 386, 165, 88, 500};
        cout << a.countArea(nums, nums.size()) << endl;
    }
    cout << "------------\n";

    {
        MaxInnerRec a;
        vector<int> nums = {3, 4, 3, 4};
        cout << a.countArea(nums, nums.size()) << endl;
    }
    cout << "------------\n";

    {
        MaxInnerRec a;
        vector<int> nums = {83, 813, 124, 495, 75, 235, 405, 256, 601, 9, 668, 730, 290,
                            203, 172, 146, 606, 435, 702, 166, 747, 829, 416, 423, 509, 195, 431, 269, 272,
                            465, 588, 106, 67, 754, 773, 678, 806, 266, 850, 378, 341, 326, 680, 237, 811,
                            138, 139, 308, 128, 354, 701, 503, 498, 818, 767, 717, 556, 843, 776, 125, 710,
                            480, 207, 610, 714, 667, 780, 587, 456, 806, 731, 603, 616, 137, 472, 10, 582,
                            281, 516, 359, 842, 548, 445, 472, 401, 524, 195, 96, 563, 712, 527, 701, 465,
                            362, 708, 378, 230, 674, 681, 355, 184, 62, 685, 117, 242, 561, 283, 785, 186,
                            68, 140, 355, 135, 35, 607, 607, 249, 448, 618, 846, 824, 695, 582, 435, 496,
                            389, 131, 714, 804, 683, 395, 674, 68, 699, 180, 315, 411, 574, 586, 347, 236,
                            398, 123, 39, 768, 486, 840, 625, 128, 454, 673, 674, 739, 393, 352, 739, 802,
                            741, 453, 837, 631, 625, 681, 646, 848, 487, 636, 847, 144, 536, 710, 26, 315,
                            66, 67, 793, 747, 191, 374, 311, 448, 672, 145, 340, 27, 168, 589, 233, 833,
                            139, 151, 433, 607, 414, 847, 649, 544, 452, 482, 530, 601, 446, 413, 460, 111,
                            285, 256, 721, 121, 188, 747, 681, 717, 792, 57, 689, 427, 583, 319, 711, 123, 573,
                            381, 677, 842, 813, 18, 332, 750, 559, 643, 15, 609, 792, 464, 820, 67, 134, 127, 286, 362, 531, 522, 212, 617, 139, 677, 77, 798, 326, 103, 229, 580, 370, 40, 267, 509, 282, 557, 156, 448, 317, 338, 498, 543, 348, 178, 466, 737, 793, 16, 711, 404, 291, 596, 641, 70, 544};

        cout << a.countArea(nums, nums.size()) << endl;
    }

    return 0;
}