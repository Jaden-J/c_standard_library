#include <stdio.h>
/////////////////////////////////////////////////////////////////
typedef int bool;
#define false 0
#define true 1

struct Date { short year, month, day; };
struct Song { char title[64];
              char artist[32];
              char composer[32];
              short duration;          // Playing time in seconds.
              struct Date published;   // Date of publication.
            };

typedef struct Song Song_t;           // Song_t is now a synonym for  // struct Song.
typedef struct { struct Cell *pFirst, *pLast; } SongList_t;
typedef struct Cell { struct Song song;     // The record data.
                      struct Cell *pNext;   // A pointer to the next record.
                    } Cell_t;

SongList_t cloneSongList( const SongList_t *pList )
{
  SongList_t newSL = { NULL, NULL };  // A new, empty list.

  Cell_t *pCell = pList->pFirst;      // Cloning starts with the first list item.
  while ( pCell != NULL && appendSong( &newSL, &pCell->song ))
    pCell = pCell->pNext;

  if  ( pCell != NULL )                 // If we didn't finish the last item,
    clearSongList( &newSL );            // discard any items cloned.

  return newSL;                         // In either case, return the list head.
}

// The function appendSong( ) dynamically allocates a new list item,
// copies the given song data to the new object, and appends it to the list.
// Arguments:    A pointer to a Song_t object to be copied, and a pointer to a
//               list to add the copy to.
// Return value: True if successful, otherwise false.

bool appendSong( SongList_t *pList, const Song_t *pSong )
{
  Cell_t *pCell = calloc( 1, sizeof(Cell_t) );  // Create a new list item.

  if ( pCell == NULL )
    return false;                               // Failure: no memory.

  pCell->song  = *pSong;                        // Copy data to the new item.
  pCell->pNext = NULL;

  if ( pList->pFirst == NULL )                  // If the list is still empty,
    pList->pFirst = pList->pLast = pCell;       // link a first (and last) item.
  else
  {                                             // If not,
    pList->pLast->pNext = pCell;                // insert a new last item.
    pList->pLast = pCell;
  }

  return true;                                  // Success.
}

// The function clearSongList( ) destroys all the items in a list.
// Argument:   A pointer to the list head.

void clearSongList( SongList_t *pList )
{
  Cell_t *pCell, *pNextCell;
  for ( pCell = pList->pFirst; pCell != NULL; pCell = pNextCell )
  {
     pNextCell = pCell->pNext;
     free( pCell );                // Release the memory allocated for each item.
  }
  pList->pFirst = pList->pLast = NULL;
}

void print_song_list(SongList_t *pList)
{


}

void testSongs()
{
    Song_t mySong = { "What It Is",
                  "Aubrey Haynie; Mark Knopfler",
                  "Mark Knopfler",
                  297,
                  { 9, 26, 2000 }
                };
    Song_t mySong2 = { "W2",
                  "2222Aubrey Haynie; Mark Knopfler",
                  "222Mark Knopfler",
                  297,
                  { 9, 26, 2000 }
                };
    Cell_t cell1= {mySong};
    Cell_t cell2 = {mySong2};
    cell1.pNext = &cell2;

}
/////////////////////////////////////////
union Data { int i; double x; char str[16]; };

void declaring_unions()
{
    union Data var, myData[100];
    var.x = 3.21;
    var.x += 0.5;
    strcpy( var.str, "Jim" );         // Occupies the place of var.x.
    myData[0].i = 50;
    int i=0;
    for (i = 0; i < 50; ++i )
        myData[i].i = 2 * i;

}
void using_union_to_illustrate_storage_of_double()
{
    union Data var;
    var.x = 1.25;
    int i=0;
    for ( i = sizeof(double) - 1; i >= 0; --i )
        printf( "%02X ", (unsigned char)var.str[i] );

}
void main_structure_ex()
{
    //declaring_unions();
    using_union_to_illustrate_storage_of_double();
}
