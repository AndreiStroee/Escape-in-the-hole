#include "GridItem.h"

GridItem::GridItem() {

}

GridItem::GridItem(char symbol): symbol(symbol) {

}
char GridItem::get_symbol() const{
	return symbol;
}