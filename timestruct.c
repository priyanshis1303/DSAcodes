#include<stdio.h>

// Define the time_struct structure
struct time_struct {
    int hour;
    int minute;
    int second;
};

// Function to input a new time
void inputTime(struct time_struct *time) {
    printf("Enter time (hh:mm:ss): ");
    scanf("%d:%d:%d", &time->hour, &time->minute, &time->second);
}

// Function to display the time
void displayTime(struct time_struct time) {
    printf("Time: %02d:%02d:%02d\n", time.hour, time.minute, time.second);
}

// Function to update the time by one second
void updateTime(struct time_struct *time) {
    time->second++; // Increment the second

    if (time->second == 60) {
        time->second = 0;
        time->minute++; // Increment the minute

        if (time->minute == 60) {
            time->minute = 0;
            time->hour++; // Increment the hour

            if (time->hour == 24) {
                time->hour = 0; // Reset to midnight (00:00:00)
            }
        }
    }
}

int main() {
    struct time_struct myTime;

    // Input a new time
    inputTime(&myTime);

    // Display the input time
    printf("\nEntered Time:\n");
    displayTime(myTime);

    // Update the time by one second
    updateTime(&myTime);

    // Display the updated time
    printf("\nUpdated Time (after one second):\n");
    displayTime(myTime);

    return 0;
}
