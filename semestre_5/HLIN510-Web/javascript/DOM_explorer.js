var divDOM;

function analyseDOM(noeud, prof) {
    if (noeud == null) return;
    let type = 0;
    console.log("blabla")
    switch (noeud.nodeType) {
        case 1 : type = 'Element'; couleur = 'lightblue';
            console.log("Element");
            break;
        case 2 : type = 'Text'; couleur = 'pink';
            break;
        case 3 : type = 'Attribut'; 
            break;
        case 9 : type = 'Document';
        default:
            break;
    }

    if (type){
        //visualiserLeNoeud(couleur, ...);
    }
    if(noeud.attributes){
        for (let num = 0; num < noeud.attributes.length; num++) {
            //visualiserLeLoeud('orange',...);
            
        }
    }
    for(let num = 0; num <noeud.childNodes.length; num++){
        analyseDOM(noeud.childNodes.item(num), prof+1);
    }
}
analyseDOM(document,10);