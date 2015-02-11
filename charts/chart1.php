
		<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>
		<?php 
	
		$num_repeating = num_repeating ("abc.txt");
		
		$abc_iteration = array_element ("abc.txt", 2);
		$pso_iteration = array_element ("pso.txt", 2);
		$opso_iteration = array_element ("opso.txt", 2);
		
		print "
		<script type=\"text/javascript\">
		
$(function () {
        $('#container').highcharts({
            title: {
                text: 'Broj iteracija potrebnih u pojedinom ponavljanju za pronalazak optimuma',
                x: -20 //center
            },
            subtitle: {
                x: -20
            },
            xAxis: {
            	title: {
                    text: 'Ponavljanja'
                },
                categories: [".$num_repeating."]
            },
            yAxis: {
                title: {
                    text: 'Iteracije'
                },
                plotLines: [{
                    value: 0,
                    width: 1,
                    color: '#808080'
                }]
            },
            tooltip: {
                valueSuffix: ' iteracija'
            },
            legend: {
                layout: 'vertical',
                align: 'right',
                verticalAlign: 'middle',
                borderWidth: 0
            },
            series: [{
                name: 'ABC',
                data: [".$abc_iteration."]
            }, {
                name: 'PSO',
                data: [".$pso_iteration."]
            }, {
                name: 'OPSO',
                data: [".$opso_iteration."]
            }]
        });
    });
    
		</script>";
		
	?>

<script src="charts/js/highcharts.js"></script>
<script src="charts/js/modules/exporting.js"></script>

<div id="container" style="min-width: 310px; height: 400px; margin-bottom: 30px;"></div>
