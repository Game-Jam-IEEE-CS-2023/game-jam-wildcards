// Run main
#include "Card.h"
#include "CardDeck.h"

int main() {
    // Usage example:
    CardDeck myDeck;

    myDeck.addCard(Card("Proto-Squire", 3, "A digital tin-knight, small but sturdy", "Block"));
    myDeck.addCard(Card("FlossBush", 2, "A flowering spawn of nature, bites!", "Sentry"));

    myDeck.displayDeck();

    return 0;
}