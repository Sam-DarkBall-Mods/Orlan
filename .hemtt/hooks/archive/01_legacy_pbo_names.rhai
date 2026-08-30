let version = HEMTT.project().version().to_string();
let main_authority = "db_orlan_" + version;

fn rename_signed_pbo(folder, old_name, new_name, authority) {
    let old_pbo = folder.join(old_name + ".pbo");
    let new_pbo = folder.join(new_name + ".pbo");
    if !old_pbo.move(new_pbo) {
        fatal("Failed to restore legacy PBO name for " + old_name);
    }

    let old_signature = folder.join(old_name + ".pbo." + authority + ".bisign");
    let new_signature = folder.join(new_name + ".pbo." + authority + ".bisign");
    if !old_signature.move(new_signature) {
        fatal("Failed to restore legacy signature name for " + old_name);
    }
}

rename_signed_pbo(
    HEMTT_OUT.join("addons"),
    "db_orlan_orlan",
    "orlan",
    main_authority
);

let support_authority = main_authority + "_db_orlan_orlan_fire_support";
let support_root = HEMTT_OUT
    .join("optionals")
    .join("@Orlan_orlan_fire_support");
rename_signed_pbo(
    support_root.join("addons"),
    "db_orlan_orlan_fire_support",
    "orlan_fire_support",
    support_authority
);
if !support_root.move(HEMTT_OUT.join("optionals").join("@orlan_fire_support")) {
    fatal("Failed to rename Orlan fire-support mod folder");
}
