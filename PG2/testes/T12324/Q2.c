#include <stdio.h>
#include <stdlib.h>

typedef struct{
 char filename[MAX_FILENAME + 1];
 char title[MAX_TITLE + 1];
 char artist[MAX_ARTIST + 1];
 char album[MAX_ALBUM + 1];
 short year;
 char comment[MAX_COMMENT + 1];
 char track;
 char genre;
} TagData;


size_t tagScan( TagData a[], size_t nElem, int (*action)(TagData *data, void *context ), void * context )
{
    int sum = 0;

    for(size_t i = 0; i < nElem; i++)
    {
        sum += action(&a[i], context);
    }
    return sum;
}

int printRecentAlbum(TagData *tag, void *context)
{
    short *date = (short *) context;
    int count = 0;
    if(tag->year > *date)
    {
        printf("Title: %s", tag->title);
        count++;
    }
    return count;
}

/*OBS: 
int Compare(const void *ptra_a, const void *ptr_b){
    int *a = (int *) ptr_a;
    int *b = (int *) ptr_b;
    return *a-*b;
}
*/

int compare(const void *key, const void *elem)
{
    short *targetYear = (short *) key;
    short *elemYear = ((TagData *)elem)->year;
    return (*targetYear - *elemYear);
}

int yearExist (TagData *a, size_t nElem, short year)
{
    TagData target;
    target.year = year;
    
    TagData *result = (TagData *) bsearch(&target, a, nElem, sizeof(TagData), compare);

    if(result != NULL)
        return 1;
        
return 0;
}