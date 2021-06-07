#pragma once
#include <vector>
#include "structures.h"
#include "wec.h"

void makeSphere(const Point center, const double ray, const unsigned int count, std::vector<Section>& out);
void makeSection(const Point pa, const Point pb, const double thickness, const unsigned int count, std::vector<Section>& out);
