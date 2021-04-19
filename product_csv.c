#include "product_csv.h"
#include <stdlib.h>
#include <string.h>
#include "backend.h"
#define FORMAT "%s%d%c%s%c%lf"

struct SProductCSV {
    char filename[60];
    char sep;
};

ProductCSV ProductCSV_create(char *filename, char sep) {
    ProductCSV new = (ProductCSV) malloc(sizeof (struct SProductCSV));

    strncpy(new->filename, filename, 60);
    new->sep = sep;

    return new;
}


void ProductCSV_delete(ProductCSV _this) {
    free(_this);
}

void ProductCSV_write(ProductCSV _this, Product p) {
    FP fp = openWrapper(_this->filename, "at");
    fprintf(fp, FORMAT,
        ftell(fp) > 0 ? "\n" : "",
        Product_getId(p),
        _this->sep,
        Product_getName(p),
        _this->sep,
        Product_getPrice(p)
    );

    fclose(fp);
}

void ProductCSV_writeAll(ProductCSV _this, Product *products, int count) {
    FP fp = openWrapper(_this->filename, "wt");

    for (int i = 0; i < count; i++) {
        fprintf(fp, FORMAT,
            i != 0 ? "\n" : "",
            Product_getId(products[i]),
            _this->sep,
            Product_getName(products[i]),
            _this->sep,
            Product_getPrice(products[i])
        );
    }

    fclose(fp);
}