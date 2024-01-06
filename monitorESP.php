<?php
header('Content-Type: application/json');

$json_url = 'http://192.168.20.153:8085/data.json';

$json_data = file_get_contents($json_url);

if ($json_data === false) {
    echo '{"Sucess":false}'; 
} else {
    $data_array = json_decode($json_data, true);
    $cpuTemp = str_replace(' °', '\'', $data_array["Children"][0]["Children"][1]["Children"][3]["Children"][18]["Value"]);
    $cpuPower = str_replace(' ', '', $data_array["Children"][0]["Children"][1]["Children"][1]["Children"][0]["Value"]);
    $gpuTemp = str_replace(' °', '\'', $data_array["Children"][0]["Children"][3]["Children"][3]["Children"][1]["Value"]);
    $gpuPower = str_replace(' ', '', $data_array["Children"][0]["Children"][3]["Children"][1]["Children"][0]["Value"]);

    $firstLine = "CPU: " . $cpuTemp . " " . $cpuPower;
    $secondLine = "GPU: " . $gpuTemp . " " . $gpuPower;

    $data = array(
        "Lines" => array(
            array("Data" => $firstLine),
            array("Data" => $secondLine)
        )
    );
    
    $json_data = json_encode($data);

    echo $json_data;
}
?>
