#include <iostream>
#include "LinkedList.h"
#include "Song.h"
#include "Podcast.h"

using namespace std;

int main() {
    // 1. Phase 1 Requirement: Templated list storing Song*
    cout << "=== Testing Templated Circular List<Song*> ===" << endl;
    LinkedList<Song*> myPlaylist;

    myPlaylist.insert(new Song("Bohemian Rhapsody", "Queen", 354));
    myPlaylist.insert(new Song("Hotel California", "Eagles", 391));
    myPlaylist.insert(new Song("Billie Jean", "Michael Jackson", 294));

    myPlaylist.displayList();

    cout << "\nTesting circular playback (4 steps on a 3-song list):" << endl;
    myPlaylist.playCurrent(); // Song 1
    myPlaylist.playNext();    // Song 2
    myPlaylist.playNext();    // Song 3 (tail)
    myPlaylist.playNext();    // Wraps back to Song 1 (head)

    // 2. Deep Dive Goal: Polymorphic list storing Media* (Songs + Podcasts)
    cout << "\n=== Testing Polymorphic Circular List<Media*> ===" << endl;
    LinkedList<Media*> myUniversalPlaylist;

    myUniversalPlaylist.insert(new Song("Stairway to Heaven", "Led Zeppelin", 482));
    myUniversalPlaylist.insert(new Podcast("C++ Templates Explained", "Code Radio", 1800, 42));

    myUniversalPlaylist.displayList();
    myUniversalPlaylist.playCurrent();
    myUniversalPlaylist.playNext();
    myUniversalPlaylist.playNext(); // Wraps back to Stairway to Heaven

    return 0;
}
