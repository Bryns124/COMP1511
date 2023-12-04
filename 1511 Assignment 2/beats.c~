// Assignment 2 21T1 COMP1511: Beats by CSE
// beats.c
//
// This program was written by Bryan Le (z5361001)
// on 19-04-2021
//
// Version 1.0.0: Assignment released.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Add any extra #includes your code needs here.

#include "beats.h"

// Add your own #defines here.
#define MIN_OCTAVE_VALUE 0
#define MAX_OCTAVE_VALUE 9
#define MIN_KEY_VALUE 0
#define MAX_KEY_VALUE 11
//////////////////////////////////////////////////////////////////////

// You don't have to use the provided struct track, you are free to
// make your own struct instead.
// If you use the provided struct track, you will have to add fields
// to store other information.

struct track {
    // TODO: You will have to add extra fields here in Stage 2.
    struct beat *head;
    int playing_status;
    int selected_beat;
    int beat_number_line;
};

// You don't have to use the provided struct beat, you are free to
// make your own struct instead.
// If you use the provided struct beat, you may add fields
// to it to store other information.

struct beat {
    // You may choose to add or change fields in this struct.
    struct note *notes;
    struct beat *next;
};

// You don't have to use the provided struct note, you are free to
// make your own struct instead.
// If you use the provided struct note, you add fields
// to it to store other information.

struct note {
    // You may choose to add or change fields in this struct.
    int octave;
    int key;
    struct note *next;
};

// Add any other structs you define here.

//////////////////////////////////////////////////////////////////////

// Add prototypes for any extra functions you create here.

int check_valid_note(Beat beat, int octave, int key);

// Return a malloced Beat with fields initialized.
Beat create_beat(void) {
    Beat new_beat = malloc(sizeof (struct beat));
    assert(new_beat != NULL);

    new_beat->next = NULL;
    new_beat->notes = NULL;

    return new_beat;
}

// You need to implement the following functions.
// You can find descriptions of what each function should do in beats.h

//////////////////////////////////////////////////////////////////////
//                        Stage 1 Functions                         //
//////////////////////////////////////////////////////////////////////

// Add a note to the end of a beat.
int add_note_to_beat(Beat beat, int octave, int key) {
    
    // Allocates memory the size of a note for a new note. 
    struct note *new_note = malloc(sizeof(struct note));
    // Returns a valid first note of the beat if it passes the check_valid_note.
    if (check_valid_note(beat, octave, key) == VALID_NOTE && beat->notes == NULL) {
        new_note->octave = octave;
        new_note->key = key;
        new_note->next = NULL;
        beat->notes = new_note;
        return VALID_NOTE;
    }
    // Returns a valid note following the first beat if it passes the check_valid_note.
    if (check_valid_note(beat, octave, key) == VALID_NOTE) {
        struct note *curr_note = beat->notes;
        new_note->octave = octave;
        new_note->key = key;
        new_note->next = NULL;
        while (curr_note->next != NULL) {
            curr_note = curr_note->next;
        }
        curr_note->next = new_note;
        return VALID_NOTE;
    }
    // If the new note is not higher than the previous note, it is not valid.
    else if (check_valid_note(beat, octave, key) == NOT_HIGHEST_NOTE) {
        return NOT_HIGHEST_NOTE;
    }
    // If the user enters a new note with a key that is negative or more than 9,
    // it is an invalid key.
    else if (check_valid_note(beat, octave, key) == INVALID_KEY) {
        return INVALID_KEY;
    }
    // If the user enters a new note with an octave that is negative or more than 11,
    // it is an invalid octave.
    else if (check_valid_note(beat, octave, key) == INVALID_OCTAVE) {
        return INVALID_OCTAVE;
    }
    
    return 0;
}

int check_valid_note(Beat beat, int octave, int key) {
    struct note *curr_note = beat->notes;
    // Checks if the values entered for the octave and the keys are valid.
    // If not valid, they return invalid octave and key.
    if (octave >= MIN_OCTAVE_VALUE && octave <= MAX_OCTAVE_VALUE &&
     key >= MIN_KEY_VALUE && key <= MAX_KEY_VALUE) {
        // Checks if the beat is empty.
        if (beat->notes == NULL) {
            return VALID_NOTE;
        }
        // Loops through the notes in the beat to check if each new note is valid.
        // Returns a valid note if passes the checks.
        while (beat->notes != NULL && curr_note != NULL) {
            // If the octave entered is more than the new octave, it is not valid.
            if (curr_note->octave > octave) {
                return NOT_HIGHEST_NOTE;
            }
            // If the octave entered is the same as the new octave and the key 
            // entered is more than the new key, it is not valid.
            if (curr_note->octave == octave && curr_note->key > key) {
                return NOT_HIGHEST_NOTE;
            }
            // If the both the octave and the note entered are the same as the new
            // octave and note, it is not valid.
            if (curr_note->octave == octave && curr_note->key == key) {
                return NOT_HIGHEST_NOTE;
            }
            curr_note = curr_note->next;
        }
        return VALID_NOTE;
    }
    // Invalid octave if the octave is negative or more than 9.
    else if (octave < MIN_OCTAVE_VALUE || octave > MAX_OCTAVE_VALUE) {
        return INVALID_OCTAVE;
    }
    // Invalid key if the key is negative or more than 11.
    else if (key < MIN_KEY_VALUE || key >= MAX_KEY_VALUE) {
        return INVALID_KEY;
    }
    return VALID_NOTE;
}

// Print the contents of a beat.
void print_beat(Beat beat) {
    struct note *curr_note = beat->notes;
    // Loops through the notes in the beat to print valid notes.
    while (curr_note != NULL) {
        // Checks if there is more than one note in the beat.
        if (curr_note->next != NULL) {
            // If the key is between 0 and 10, it is printed with a 0
            // at the front of the digit.
            // Prints a | after it if there is more than one note 
            // being entered into the beat.
            if (curr_note->key >= 0 && curr_note->key < 10) {
                printf("%d 0%d |", curr_note->octave, curr_note->key);
            }
            // If the key is more than 10, it prints itself.
            if (curr_note->key >= 10) {
                printf("%d %d |", curr_note->octave, curr_note->key);
            }
        }
        // Checks if there is one note in the beat.
        if (curr_note->next == NULL) {
            if (curr_note->key >= 0 && curr_note->key < 10) {
                printf("%d 0%d", curr_note->octave, curr_note->key);
            }
            if (curr_note->key >= 10) {
                printf("%d %d", curr_note->octave, curr_note->key);
            } 
        }
        curr_note = curr_note->next;
    }
    printf("\n");
}
// Count the number of notes in a beat that are in a given octave.
int count_notes_in_octave(Beat beat, int octave) {
    int number_of_notes = 0;
    struct note *curr_note = beat->notes;
    // Loops through the notes in the beat.
    while (curr_note != NULL) {
        // Moves from note to note. 
        // Counts the number of notes.
        if (curr_note->octave == octave) {
            number_of_notes++;
        }
        curr_note = curr_note->next;
    }
    return number_of_notes;
}

//////////////////////////////////////////////////////////////////////
//                        Stage 2 Functions                         //
//////////////////////////////////////////////////////////////////////

// Return a malloced track with fields initialized.
Track create_track(void) {
    
    Track new_track = malloc(sizeof(struct track));
    new_track->head = NULL;
    new_track->selected_beat = 0;
    new_track->beat_number_line = 0;
    new_track->playing_status = TRACK_STOPPED;
    return new_track;
}

// Add a beat after the current beat in a track.
void add_beat_to_track(Track track, Beat beat) {
    // Checks if the track is 'stopped'.
    if (track->playing_status == TRACK_STOPPED) {
        // Checks if the number of the line of the beat is 0.
        // Adds a beat.
        if (track->beat_number_line == 0) {
            beat->next = NULL;
            track->head = beat;
            track->beat_number_line++;
        }
        // Checks if the number of the line of the beat is more than 0.
        // Adds a beat.
        else if (track->beat_number_line > 0) {
            beat->next = track->head;
            track->head = beat;
            track->beat_number_line++;
        }
    }
    // Checks if the track is 'playing'.
    else if (track->playing_status == TRACK_PLAYING) {
        Beat curr_beat = track->head;
        int beat_digit = 1;
        // Loops to match the beat digit with the selected beat.
        while (beat_digit < track->selected_beat) {
            beat_digit++;
            curr_beat = curr_beat->next;
        }
        // Checks it the track has one beat.
        // Adds beat.
        if (curr_beat->next == NULL) {
            Beat final_beat = track->head;
            beat->next = NULL;
            while (final_beat->next != NULL) {
                final_beat = final_beat->next;
            }
            final_beat->next = beat;
        }
        // Checks if the track has more than one beat.
        // Adds beat.
        else if (curr_beat->next != NULL) {
            beat->next = curr_beat->next;
            curr_beat->next = beat;
        }
    }
}
// Set a track's current beat to the next beat.
int select_next_beat(Track track) {
    Beat curr_beat = track->head;
    int beat_digit = 1;
    // Loops to match the beat digit with the selected beat number.
    while (beat_digit < track->selected_beat) {
        beat_digit++;
        curr_beat = curr_beat->next;
    }
    // Checks if the track has any beats.
    // If not, the track is 'stopped'.
    if (curr_beat == NULL) {
        track->playing_status = TRACK_STOPPED;
        return TRACK_STOPPED;
    }
    // Checks if the track is 'stopped'.
    // If the selected beat is the first beat,
    // then the track is still 'playing'.
    else if (track->playing_status == TRACK_STOPPED) {
        track->selected_beat = 1;
        track->playing_status = TRACK_PLAYING;
        return TRACK_PLAYING;
    }
    // Checks if the track is 'playing'.
    else if (track->playing_status == TRACK_PLAYING) {
        // If the selected beat is the track's last beat,
        // then the track is 'stopped'.
        if (curr_beat->next == NULL) {
            track->selected_beat = 0;
            track->playing_status = TRACK_STOPPED;
            return TRACK_STOPPED;
        }
        // If the selected beat is not the track's last beat,
        // then the track is playing.
        else if (curr_beat->next != NULL) {
            track->playing_status = TRACK_PLAYING;
            track->selected_beat++;
            return TRACK_PLAYING;
        }
    }
    return 0;
}

// Print the contents of a track.
void print_track(Track track) {
    int beat_digit = 1;
    Beat curr_beat = track->head;
    // Checks if the track has any beat.
    // If none, print nothing.
    if (curr_beat == NULL) {
        printf(" ");
    }
    // Loops through the beats in the track to check is the beat
    // is a selected beat.
    while (curr_beat != NULL) {
        // Prints a > next to the selected beat.
        if (beat_digit == track->selected_beat) {
            printf(">");
        }
        // If the beat is not a selected beat, it
        // prints nothing.
        else if (beat_digit != track->selected_beat) {
            printf(" ");
        }
        printf("[%d] ", beat_digit);
        print_beat(curr_beat);
        beat_digit++;
        curr_beat = curr_beat->next;
    }
}

// Count beats after the current beat in a track.
int count_beats_left_in_track(Track track) {
    Beat curr_beat = track->head;
    int beats_left = 0;
    int curr_beat_digit = 0;
    // Checks if the track is 'playing'.
    if (track->playing_status == TRACK_PLAYING) {
        beats_left = 0;
        curr_beat_digit = 0;
        curr_beat = track->head;
        // Loops through the track to match the current 
        // beat digit with the selected beat.
        while (curr_beat_digit < track->selected_beat) {
            curr_beat = curr_beat->next;
            curr_beat_digit++;
        }
        // When the current beat digit matches the selected
        // beat, it counts the number of beats left in the track.
        while (curr_beat != NULL) {
            curr_beat = curr_beat->next;
            beats_left++;
        }
    }
    // Checks if the track is 'stopped'.
    if (track->playing_status == TRACK_STOPPED) {
        int counter_beat_track_stopped = 0;
        curr_beat = track->head;
        // Counts the total number of beats in the track.
        while (curr_beat != NULL) {
            curr_beat = curr_beat->next;
            counter_beat_track_stopped++;
        }
        return counter_beat_track_stopped;
    }
    return beats_left;
}

//////////////////////////////////////////////////////////////////////
//                        Stage 3 Functions                         //
//////////////////////////////////////////////////////////////////////

// Free the memory of a beat, and any memory it points to.
void free_beat(Beat beat) {
    struct note *curr_note = beat->notes;
    struct note *prev_note = NULL;
    while (curr_note != NULL) {
        prev_note = curr_note;
        curr_note = curr_note->next;
        free(prev_note);
    }
    free(beat);
}

// Free the memory of a track, and any memory it points to.
void free_track(Track track) {
    Beat curr_beat = track->head;
    Beat prev_beat = NULL;
    while (curr_beat != NULL) {
        prev_beat = curr_beat;
        curr_beat = curr_beat->next;
        free(prev_beat);
    }
    free(track);
}

// Remove the currently selected beat from a track.
int remove_selected_beat(Track track) {
    // Checks if the track is 'stopped'.
    // If the track is 'stopped', the function
    // does nothing.
    if (track->playing_status == TRACK_STOPPED) {
        track->playing_status = TRACK_STOPPED;
        return TRACK_STOPPED;
    }
    // Checks if the track is 'playing'.
    else if (track->playing_status == TRACK_PLAYING) {
        Beat curr_beat = track->head;
        Beat prev_beat = NULL;
        int beat_digit = 1;
        // Loops through the beats in the track until, 
        // the beat digit matches the selected beat. 
        while (beat_digit < track->selected_beat) {
            prev_beat = curr_beat;
            curr_beat = curr_beat->next;
            beat_digit++;
        }
        // Checks if the selected beat is the last
        // beat in the track
        if (curr_beat->next == NULL) {
            // Checks if the selected beat is the only
            // beat in the track. If so, the selected
            // beat is freed and no beat will be currently
            // selected. The track is 'stopped'.
            if (beat_digit == 1) {
                track->head = NULL;
                free_beat(curr_beat);
                track->selected_beat = 0;
                track->playing_status = TRACK_STOPPED;
                return TRACK_STOPPED;
            }
            // If the selected beat is not the only beat,
            // the selected beat is freed regardless. There
            // will be no beat currently selected and the 
            // track is 'stopped'.
            else if (beat_digit != 1) {
                prev_beat->next = NULL;
                free_beat(curr_beat);
                track->selected_beat = 0;
                track->playing_status = TRACK_STOPPED;
                return TRACK_STOPPED;
            }
        }
        // Checks if the beat is not the 
        // last beat in the track.
        else if (curr_beat->next != NULL) {
            // Checks if the first beat is the selected
            // beat. If so, the beat is freed and the
            // following beat will be the selected beat.
            // The track is still 'playing'.
            if (beat_digit == 1) {
                track->head = curr_beat->next;
                free_beat(curr_beat);
                track->playing_status = TRACK_PLAYING;
                return TRACK_PLAYING;
            }
            // If the selected beat is any beat between 
            // the first and the last beat, it is freed
            // regardless. The following beat will be the
            // selected beat and the track will still be
            // playing.
            else if (beat_digit != 1) {
                prev_beat->next = curr_beat->next;
                free_beat(curr_beat);
                track->playing_status = TRACK_PLAYING;
                return TRACK_PLAYING;
            }
        }
    }
    return 0;
}
