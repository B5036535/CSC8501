#pragma once
class Tile
{
public:
	char character;

	virtual bool canBeMovedOn() = 0;
};
