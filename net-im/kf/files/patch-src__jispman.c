--- src/jispman.c.orig	Sun Apr 10 13:03:54 2005
+++ src/jispman.c	Thu Nov 24 23:08:21 2005
@@ -162,13 +162,14 @@
  **/
 KfJisp *kf_jisp_manager_get_jisp_for_jid (KfJispManager *jispman, const gchar *jid)
 {
+	GList *tmp;
+	KfJispPattern *pattern;
+
 	g_return_val_if_fail (jispman, NULL);
 	g_return_val_if_fail (jid, NULL);
 	
-	GList *tmp;
-
 	for (tmp = jispman->patterns; tmp; tmp = tmp->next) {
-		KfJispPattern *pattern = tmp->data;
+		pattern = tmp->data;
 
 		if (g_pattern_match_string (pattern->gpat, jid))
 			return pattern->jisp;
@@ -188,10 +189,12 @@
  **/
 KfJispPattern *kf_jisp_pattern_new (const gchar *pattern, KfJisp *jisp)
 {
+	KfJispPattern *pat;
+
 	g_return_val_if_fail (pattern, NULL);
 	g_return_val_if_fail (jisp, NULL);
 	
-	KfJispPattern *pat = g_new0 (KfJispPattern, 1);
+	pat = g_new0 (KfJispPattern, 1);
 	pat->pattern = g_strdup (pattern);
 	pat->jisp = kf_jisp_ref (jisp);
 	pat->gpat = g_pattern_spec_new (pattern);
