#include <stdio.h>

//#include <binpack.h>

unsigned int worst_fit(unsigned int binsize, unsigned int *sizes, unsigned int *bins,
        unsigned int numitems)
{
    unsigned int bins_used = 0;
    unsigned int item;
    maxheap *heap = maxheap_create();
    if (heap == NULL) {
        return 0;
    }
    for (item = 0; item < numitems; item++) {
        bin *b = maxheap_remove_max(heap);
        if (b && b->capacity < sizes[item]) {
            /* Too small; put b back */
            maxheap_add(heap, b, b->capacity);
            b = NULL;
        }
        if (!b) {
            /* Create a new bin */
            b = bin_create(bins_used, binsize);
            bins_used++;
        }
        bins[item] = b->id;
        bin_use(b, sizes[item]);
        maxheap_add(heap, b, b->capacity);
    }
    maxheap_for_each(heap, (maxheap_forfn)bin_delete);
    maxheap_delete(heap);
    return bins_used;
}

int main(void)
{
    unsigned int sizes[] = {1, 4, 9, 4, 1, 5, 8, 3, 2, 5, 7, 3, 2, 6};
    const unsigned int numitems = 14;
    unsigned int bins[numitems];
    const unsigned int binsize = 10;
    unsigned int item;
    unsigned int bins_used = fit(binsize, sizes, bins, numitems);
    printf("%d bins were used\n", bins_used);
    for (item = 0; item < numitems; item++) {
        printf("Item #%d (size %d) is in bin %d\n", item, sizes[item], bins[item]);
    }
    return 0;
}
