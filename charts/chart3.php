		<?php 
	
		$num_repeating = num_repeating ("abc.txt");
		
		$abc_opt = array_element ("abc.txt", 4);
		$pso_opt = array_element ("pso.txt", 4);
		$opso_opt = array_element ("opso.txt", 4);
		
		print "

		<script type=\"text/javascript\">
$(function () {
        $('#container3').highcharts({
            title: {
                text: 'Odstupanje od referentne točke u pojedinom ponavljanju',
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
                    text: 'Odstupanje'
                },
                plotLines: [{
                    value: 0,
                    width: 1,
                    color: '#808080'
                }]
            },
            tooltip: {
                valueSuffix: ''
            },
            legend: {
                layout: 'vertical',
                align: 'right',
                verticalAlign: 'middle',
                borderWidth: 0
            },
            series: [{
                name: 'ABC',
                data: [".$abc_opt."]
            }, {
                name: 'PSO',
                data: [".$pso_opt."]
            },  {
                name: 'OPSO',
                data: [".$opso_opt."]
            }]
        });
    });
    

		</script>";
		
	?>

<div id="container3" style="min-width: 310px; height: 400px; margin-bottom: 30px;"></div>


<?php

echo ($abc_opt."<br />".$pso_opt."<br />".$opso_opt);

 ?>