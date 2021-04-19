#pragma once
#include "product.h"

typedef struct SProductCSV *ProductCSV;

ProductCSV ProductCSV_create(char *filename, char sep);
void ProductCSV_delete(ProductCSV _this);
void ProductCSV_write(ProductCSV _this, Product p);
void ProductCSV_writeAll(ProductCSV _this, Product *products, int count);