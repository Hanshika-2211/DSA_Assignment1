#include <iostream>
#include <string>
using namespace std;

class SongNode {
public:
    string title;
    string producer;
    string singer;
    string genre;
    SongNode* prev;
    SongNode* next;

    SongNode(string t, string p, string s, string g) {
        title = t;
        producer = p;
        singer = s;
        genre = g;
        prev = nullptr;
        next = nullptr;
    }
};

class MusicPlaylist {
private:
    SongNode* head;
    SongNode* tail;
    SongNode* current;

public:
    MusicPlaylist() {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }

    void addSong(string title, string producer, string singer, string genre) {
        SongNode* newNode = new SongNode(title, producer, singer, genre);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            current = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayPlaylist() {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        SongNode* temp = head;
        while (temp != nullptr) {
            cout << "Title: " << temp->title << ", Producer: " << temp->producer << ", Singer: " << temp->singer << ", Genre: " << temp->genre << "\n";
            temp = temp->next;
        }
    }

    void displayBySinger(string singer) {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        SongNode* temp = head;
        while (temp != nullptr) {
            if (temp->singer == singer) {
                cout << "Title: " << temp->title << ", Producer: " << temp->producer << ", Singer: " << temp->singer << ", Genre: " << temp->genre << "\n";
            }
            temp = temp->next;
        }
    }

    void displayByGenre(string genre) {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        SongNode* temp = head;
        while (temp != nullptr) {
            if (temp->genre == genre) {
                cout << "Title: " << temp->title << ", Producer: " << temp->producer << ", Singer: " << temp->singer << ", Genre: " << temp->genre << "\n";
            }
            temp = temp->next;
        }
    }

    void playNext() {
        if (current == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        if (current->next != nullptr) {
            current = current->next;
            cout << "Next song: " << current->title << "\n";
        } else {
            cout << "End of playlist. No more songs to play.\n";
        }
    }

    void playPrevious() {
        if (current == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        if (current->prev != nullptr) {
            current = current->prev;
            cout << "Previously played: " << current->title << "\n";
        } else {
            cout << "Beginning of playlist. No previous songs.\n";
        }
    }

    void playSong(string title) {
        SongNode* temp = head;
        while (temp != nullptr) {
            if (temp->title == title) {
                current = temp;
                cout << "Now playing: " << current->title << "\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Song not found in the playlist.\n";
    }
};
int main() {
    MusicPlaylist playlist;

    playlist.addSong("Tum Hi Ho", "Bhushan Kumar", "Arijit Singh", "Romantic");
    playlist.addSong("Channa Mereya", "Karan Johar", "Arijit Singh", "Soulful");
    playlist.addSong("Dil Diyan Gallan", "Aditya Chopra", "Atif Aslam", "Love");
    playlist.addSong("Ghoomar", "Sanjay Leela Bhansali", "Shreya Ghoshal", "Traditional");

    cout << "Playlist:\n";
    playlist.displayPlaylist();

    string singer;
    cout << "\nEnter singer name to display songs: ";
    getline(cin, singer);
    cout << "Songs by " << singer << ":\n";
    playlist.displayBySinger(singer);

    string genre;
    cout << "\nEnter genre to display songs: ";
    getline(cin, genre);
    cout << "Songs in " << genre << " genre:\n";
    playlist.displayByGenre(genre);

    string song;
    cout << "\nEnter song title to play: ";
    getline(cin, song);
    playlist.playSong(song);

    cout << "\nPlaying next song:\n";
    playlist.playNext();

    cout << "\nPlaying previous song:\n";
    playlist.playPrevious();

    return 0;
}