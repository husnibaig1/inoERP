<?php
if (!empty($_GET['fa_asset_id']) && empty($fa_asset_assignment_object)) {
 $fa_asset_assignment_object = fa_asset_assignment::find_by_parent_id($_GET['fa_asset_id']);
} 

if(empty($fa_asset_assignment_object)){
 $fa_asset_assignment_object = [new fa_asset_assignment()];
}

$pageno = !empty($_GET['pageno']) ? $_GET['pageno'] : 1;
$per_page = !empty($_GET['per_page']) ? $_GET['per_page'] : 10;
$total_count = count($fa_asset_assignment_object);
$pagination = new pagination($pageno, $per_page, $total_count);
$pagination->setProperty('_path', 'form');
$position = ($pageno - 1) * $per_page;

?>
