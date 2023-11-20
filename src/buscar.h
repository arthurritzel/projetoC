Evento *buscar_evento(Evento *raiz, int dia, int mes) {
	//Comparando se a data do evento existe ou se o evento é a propria raiz
    if (raiz -> NULL || (mes == raiz->mes && dia == raiz->dia)) {
        return raiz; 
    }

    if (mes < raiz->mes || (mes == raiz->mes && dia < raiz->dia)){ 
        return buscar_evento(raiz->esquerda, dia, mes);	// buscando evento na esquerda
    } else {
        return buscar_evento(raiz->direita, dia, mes);	// buscando evento na direita
    } 
}