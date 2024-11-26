#include <iostream>
#include <queue>
#include <string>

using namespace std;


enum EventType
{
    TAP,
    SWIPE
};

struct Event {
    EventType eventType;
    int x, y;
    time_t timestamp;


    Event(EventType type, int xCoord, int yCoord)
        : eventType(type), x(xCoord), y(yCoord), timestamp(time(nullptr)) {}
};


class EventProcessor {
public:

    void enqueueEvent(const Event& e) {
        eventQueue.push(e);
    }


    void processEvents() {
        while (!eventQueue.empty()) {
            Event e = eventQueue.front();
            eventQueue.pop();
            handleEvent(e);
        }
    }

private:
    queue<Event> eventQueue;


    void handleEvent(const Event& e) {
        cout << "Event at [" << e.x << ", " << e.y << "] at timestamp " << e.timestamp << endl;

        switch (e.eventType) {
        case TAP:
            cout << "Event: TAP at (" << e.x << ", " << e.y << ")" << endl;
            break;
        case SWIPE:
            cout << "Event: SWIPE ";
            if (e.x > 50) {
                if (e.y > 50)
                    cout << "Up swipe";
                else
                    cout << "Down swipe";
            }
            else if (e.x < -50) {
                if (e.y > 50)
                    cout << "Right swipe";
                else
                    cout << "Left swipe";
            }
            cout << endl;
            break;
        default:
            cout << "Unknown event type!" << endl;
        }
    }
};

void generateRandomEvents(EventProcessor& processor, int numEvents) {
    for (int i = 0; i < numEvents; ++i)
    {
        EventType type = (rand() % 2 == 0) ? TAP : SWIPE;

        int x = rand() % 101;
        int y = rand() % 101;

        Event e(type, x, y);
        processor.enqueueEvent(e);
    }
}

int main()
{
    srand(static_cast<unsigned>(time(0)));

    EventProcessor processor;

    generateRandomEvents(processor, 5);

    processor.processEvents();

    return 0;
}