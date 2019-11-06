var http="https://webpeda.etu.umontpellier.fr/e20160018322/TP%203%20OpenLayers%20OpenStreetMaps%20%20carte%20interactive-20191106/JSON/";
var tab_tmp;
$.getJSON(http+"themes.json",function(data){

    var map = new ol.Map({
        target: 'map',
        layers: [new ol.layer.Tile({source : new ol.source.OSM()})],
        view: new ol.View({
            center: new ol.proj.fromLonLat([3.87667,43.6111]),
            zoom:15
        })
    });

    var tab_data = [];
    data.forEach(function(a){
        var tab_inter = [];
        $.getJSON(http+a.lien,function(j){
            tab_tmp = [];
            j.forEach(function(e){
                tab_tmp.push(e);
                //console.log(e)
            });
            //console.log(tab_tmp);
            tab_inter.push(a.nom);
            tab_inter.push(tab_tmp);
            tab_data.push(tab_inter);
        })
        }
    );
    console.log(tab_data);
    $("body").append("je suis la pkus belle");

});