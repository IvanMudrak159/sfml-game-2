#include "Drawable.h"

Drawable::Drawable(int layer) : layer(layer)
{
}

int Drawable::GetLayer() const
{
	return layer;
}
