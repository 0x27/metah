
		<?php 
	
		$num_repeating = num_repeating ("abc.txt");
		
		$abc_time = array_element ("abc.txt", 3);
		$pso_time = array_element ("pso.txt", 3);
		$opso_time = array_element ("opso.txt", 3);
		
		print "
			
		<script type=\"text/javascript\">
$(function () {
        $('#container2').highcharts({
            title: {
                text: 'Vrijeme potrebno za pronalazak optimuma u pojedinom ponavljanju',
                x: -20 //center
            },
            subtitle: {
                x: -20
            },
            xAxis: {
	            title: {
                    text: 'Ponavljanje'
                },
                categories: [".$num_repeating."]
            },
            yAxis: {
                title: {
                    text: 'Vrijeme (milisekunde)'
                },
                plotLines: [{
                    value: 0,
                    width: 1,
                    color: '#808080'
                }]
            },
            tooltip: {
                valueSuffix: ' milisekunda'
            },
            legend: {
                layout: 'vertical',
                align: 'right',
                verticalAlign: 'middle',
                borderWidth: 0
            },
            series: [{
                name: 'ABC',
                data: [".$abc_time."]
            }, {
                name: 'PSO',
                data: [".$pso_time."]
            }, {
                name: 'OPSO',
                data: [".$opso_time."]
            }]
        });
    });
    

		</script>";
		
		?>

<div id="container2" style="min-width: 310px; height: 400px; margin-bottom: 30px;"></div>
