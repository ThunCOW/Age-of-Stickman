using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(menuName = "SpineAttachment/AttachmentsList")]
public class SpineAttachmentSO : ScriptableObject
{
    public List<SpineAttachment> SpineAttachmentList;
}