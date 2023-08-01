#include <stdio.h>
#include <time.h>

void delay(unsigned int milliseconds) {
    clock_t start_time = clock();
    while (clock() - start_time < milliseconds);
}

void displayTime(int hours, int minutes, int seconds) {
    system("cls"); // For Windows. Use "clear" for Linux/Mac

    // Display time in larger font (minimum 3 lines)
    printf("Time: %02d : %02d : %02d\n", hours, minutes, seconds);
    printf("\n");
}

int main() {
    char choice;
    int hours = 0, minutes = 0, seconds = 0;

    printf("What would you like to do?\n");
    printf("1. Stopwatch\n");
    printf("2. Countdown\n");
    scanf("%c", &choice);

    if (choice == '1') {
        time_t start_time = time(NULL);
        time_t current_time;

        printf("Stopwatch started. Press 'S' to stop.\n");

        while (1) {
            if (kbhit()) {
                char ch = getchar();
                if (ch == 'S' || ch == 's') {
                    break;
                }
            }

            current_time = time(NULL);
            seconds = (int)(current_time - start_time);
            minutes = seconds / 60;
            hours = minutes / 60;

            displayTime(hours, minutes % 60, seconds % 60);

            delay(1000); // Delay for 1 second
        }

        printf("Stopwatch stopped.\n");
    }
    else if (choice == '2') {
        printf("Enter the countdown time (hh:mm:ss): ");
        scanf("%d:%d:%d", &hours, &minutes, &seconds);

        while (hours > 0 || minutes > 0 || seconds > 0) {
            if (kbhit()) {
                char ch = getchar();
                if (ch == 'S' || ch == 's') {
                    break;
                }
            }

            displayTime(hours, minutes, seconds);

            if (seconds == 0) {
                if (minutes == 0) {
                    hours--;
                    minutes = 59;
                    seconds = 59;
                } else {
                    minutes--;
                    seconds = 59;
                }
            } else {
                seconds--;
            }

            delay(1000); // Delay for 1 second
        }

        printf("Countdown stopped.\n");
    } else {
        printf("Invalid choice. Please enter 1 or 2.\n");
    }

    return 0;
}
