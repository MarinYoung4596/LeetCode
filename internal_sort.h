/**
 * @brief 各种内排序方法
 * @note 仅为原理实现，不做异常输入检查
 */

#ifndef _INTERNAL_SORT_H_
#define _INTERNAL_SORT_H_

#include "util.h"
#include <vector>

/**
 * @brief: 冒泡排序
 * 重复地走访过要排序的数列，一次比较两个元素，如果他们的顺序错误就把他们交换过来。
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 * 稳定排序
 */
template<typename Type>
void bubble_sort(std::vector<Type> &v, int left, int right) {
    for (int i = left; i < right; i++) {
        for (int j = i + 1; j < right; j++) {
            if (v[i] > v[j]) {
                std::swap(v[i], v[j]);
            }
        }
    }
}

/**
 * @brief 选择排序
 * 每一次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的起始位置，直到全部待排序的数据元素排完。
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 * 不稳定排序
 */
template<typename Type>
void select_sort(std::vector<Type> &v, int left, int right) {
    for (int i = left; i < right; i++) {
        int min_pos = i;
        for (int j = i + 1; j < right; j++) {
            if (v[min_pos] > v[j]) {
                min_pos = j;
            }
        }
        if (i != min_pos) {
            std::swap(v[i], v[min_pos]);
        }
    }
}

/**
 * @brief: 插入排序
 * 每步将一个待排序的纪录，按其关键值的大小插入前面已经排序的文件中适当位置上，直到全部插入完为止。
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 * 不稳定排序
 */
template<typename Type>
void insert_sort(std::vector<Type> &v, int left, int right) {
    for (int i = left + 1; i < right; i++) {
        //如果v[j]前一个数据v[j-1] > v[j]，就交换v[j]和v[j-1]，再j--直到v[j-1] <= v[j]
        for (int j = i - 1;
                j >= 0 && v[j] > v[j + 1];
                --j) {
            std::swap(v[j], v[j + 1]);
        }
    }
}

/**
 * @brief 快速排序
 * 通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，
 * 然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。
 * 时间复杂度：O(NlogN) (输入有序时退化成 O(N^2))
 * 空间复杂度：O(logN)
 * 不稳定排序
 * https://en.wikipedia.org/wiki/Quicksort
 */
template <typename Type>
int partition_v1(std::vector<Type> &v, int begin, int end) {
    Type pivot = v[end]; // 以最后一个元素为基准
    int i = begin;
    for (auto j = begin; j < end; ++j) { // 从前往后扫描
        if (v[j] < pivot) { // 遇到比pivot小的元素, 挪到前面去
            // 这里i可以理解为比pivot小的元素总数(相对于所有v而言)
            std::swap(v[i], v[j]);     //  <
            ++i;
        }
    }
    std::swap(v[i], v[end]); // 循环执行完,下标<i的所有元素都比pivot小, swap之后, 即实现了partition的目标
    return i;
}

// 效率不高，但好理解，效率高
template <typename Type>
int partition_v2(std::vector<Type> &v, int begin, int end) {
    Type pivot = v[begin];
    while (begin < end) {
        while (begin < end && pivot <= v[end]) {  // 符合预期
            --end;
        }
        std::swap(v[begin], v[end]);  // v[end] < pivot, 交换，这样所有 pivot 放在了 end 左边
        while (begin < end && v[begin] <= pivot) {  // 符合预期
            ++begin;
        }
        std::swap(v[begin], v[end]);  // begin 放在pivot 右边
    }
    return begin;
}

// 和上面v2方式类似，效率同样不高
template <typename Type>
int partition_v3(vector<Type>& v, int begin, int end) {
    Type pivot = v[begin];
    while (begin < end) {
        while (end > begin && v[end] >= pivot) {
            --end;
        }
        v[begin] = v[end];
        while (begin < end && v[begin] <= pivot) {
            ++begin;
        }
        v[end] = v[begin];
    }
    v[begin] = pivot;
    return begin;
}

// 注意：左闭右闭 区间
template<typename Type>
void quick_sort(std::vector<Type> &v, int left, int right) {
    if (left >= right) {        // do not sort 0 or 1 element
        return;
    }
    int k = partition_v2(v, left, right);
    quick_sort(v, left, k - 1);
    quick_sort(v, k + 1, right);
}

/**
 * @brief 归并排序
 * 采用分治法.将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。
 * 时间复杂度：O(NlogN)
 * 空间复杂度：O(N)
 * 稳定排序
 * https://en.wikipedia.org/wiki/Merge_sort
 */
template <typename Type>
void merge(std::vector<Type> &v, int left, int mid, int right) {
    std::vector<Type> tmp(right - left + 1, Type());
    int i = left;
    int j = mid + 1;
    int k = 0; // 每次都是从0开始,因为 tmp 只是暂存
    while (i <= mid && j <= right) {
        if (v[i] <= v[j]) {
            tmp[k++] = v[i++];
        } else {
            tmp[k++] = v[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = v[i++];
    }
    while (j <= right) {
        tmp[k++] = v[j++];
    }
    for (i = 0; i < k; i++) { // 最后还要 copy 回原数组,注意这里下标是 left+i
        v[left + i] = tmp[i];
    }
}

template <typename Type>
void merge_sort(std::vector<Type> &v, int left, int right) {
    if (right <= left) {  // 防止相邻的两个元素逆序
        return;
    }
    int mid = left + (right - left) / 2;
    merge_sort(v, left, mid);
    merge_sort(v, mid + 1, right);
    merge(v, left, mid, right);
}


/**
 * @brief 希尔排序
 * 把记录按下标的一定增量分组，对每组使用直接插入排序算法排序；
 * 随着增量逐渐减少，每组包含的关键词越来越多，
 * 当增量减至1时，整个文件恰被分成一组，算法终止.
 * 时间复杂度：O(n^1.5)
 * 空间复杂度：O(1)
 * 不稳定排序
 * https://en.wikipedia.org/wiki/Shellsort
 */
template <typename Type>
void ins_sort_2(std::vector<Type> &v, int start, int incr) {
    int n = v.size();
    for (int i = start + incr; i < n; i += incr) {
        for (int j = i; j >= incr; j -= incr) {
            if (v[j] < v[j - incr]) {
                std::swap(v[j], v[j - incr]);
            }
        }
    }
}

template <typename Type>
void shell_sort(std::vector<Type> &v) {
    int n = v.size();
    for (int i = n / 2; i > 2; i /= 2) {
        for (int j = 0; j < i; j++) {
            ins_sort_2(v, j, i);
        }
    }
    ins_sort_2(v, 0, 1);
}


/**
 * @brief 堆排序
 * 利用堆的性质：子节点的键值总是小于（或大于）它的父节点
 * 时间复杂度：O(NlogN);
 * 空间复杂度：O(1);
 * 不稳定排序
 * https://en.wikipedia.org/wiki/Heapsort
 */
template <typename Type>
void heap_adjust(std::vector<Type> &v, int start, int end) {
    auto left = 2 * start;
    auto right = left + 1;
    auto largest = start;          // 建最大堆，取左右子树的最大值，同时判断左右子树是否存在
    if (left <= end && v[largest] < v[left]) {
        largest = left;
    }
    if (right <= end && v[largest] < v[right]) {
        largest = right;
    }
    if (largest != start) {   //
        std::swap(v[start], v[largest]); // 将当前结点与左右子树中的大者交换
        heap_adjust(v, largest, end); // 再对其中不满足堆条件的子树执行adjust操作（另外一棵树肯定满足条件）
    }
}

template <typename Type>
void build_heap(std::vector<Type> &v) {
    // (start is assigned the index in 'v' of the last parent node)
    // (the last element in a 0-based array is at index count-1; find the parent of that element)
    for (int i = (v.size() - 1) / 2; i >= 0; --i) {  // 最后一个元素的父节点
        // (sift down the node at index 'start' to the proper place such that all nodes below the start index are in heap order)
        heap_adjust(v, i, v.size());
    }  // (after sifting down the root all nodes/elements are in heap order)
}

template <typename Type>
void heap_sort(std::vector<Type> &v) {
    build_heap(v);                // Build the heap in array v so that largest value is at the root)
    for (int i = v.size() - 1; i > 0; --i) {   // 从最后一个元素开始调整序列
        // v[0] is the root and largest value. The swap moves it in front of the sorted elements.
        std::swap(v[i], v[0]);                 // 交换 堆顶元素 和 堆中最后一个元素，相当于pop堆顶
        heap_adjust(v, 0, i - 1);              // 调整堆
    }
}

#endif // _INTERNAL_SORT_H_
