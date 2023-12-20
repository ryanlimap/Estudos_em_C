//Códigos da questão de DynVec da prova 1 substitutiva
DynVec *dv_unique(DynVec *dv) {
    DynVec *novodv = dv_create();
    int tamanho = dv_size(dv);

    for(int i = 0; i <= tamanho; i++) {
        float novovet = dv_get(dv, i);
        if(!dv_is_in(novodv, novovet)) {
            dv_insert(novodv, novovet);
        }
    }
}