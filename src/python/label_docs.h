#pragma once
#include <Python.h>

#define DOC_SIGNATURE_EN(name, signature, en) PyDoc_STRVAR(name, signature "\n--\n\n" en)
#define DOC_VARIABLE_EN(name, en) PyDoc_STRVAR(name, en)
#ifdef DOC_KO
#define DOC_SIGNATURE_EN_KO(name, signature, en, ko) PyDoc_STRVAR(name, signature "\n--\n\n" ko)
#define DOC_VARIABLE_EN_KO(name, en, ko) PyDoc_STRVAR(name, ko)
#else
#define DOC_SIGNATURE_EN_KO(name, signature, en, ko) PyDoc_STRVAR(name, signature "\n--\n\n" en)
#define DOC_VARIABLE_EN_KO(name, en, ko) PyDoc_STRVAR(name, en)
#endif

/*
	class Candidate
*/
DOC_SIGNATURE_EN_KO(Candidate___init____doc__,
	"Candidate()",
	u8R""()"",
u8R""()"");

DOC_VARIABLE_EN_KO(Candidate_words__doc__,
	u8R""(words of the candidate for topic label (read-only))"",
	u8R""(���� ���̺��� �ĺ� (�б�����))"");

DOC_VARIABLE_EN_KO(Candidate_score__doc__,
	u8R""(score of the candidate (read-only))"",
	u8R""(�ĺ��� ����(�б�����))"");

DOC_VARIABLE_EN_KO(Candidate_name__doc__,
	u8R""(an actual name of the candidate for topic label)"",
	u8R""(���� ���̺��� ���� �̸�)"");

/*
	class PMIExtractor
*/
DOC_SIGNATURE_EN_KO(Extractor_extract__doc__,
	"extract(self, topic_model)",
	u8R""(Return the list of `tomotopy.label.Candidate`s extracted from `topic_model`

Parameters
----------
topic_model
    an instance of topic model with documents to extract candidates
)"",
	u8R""(`topic_model`�κ��� ����� ���� ���̺� �ĺ��� `tomotopy.label.Candidate`�� ����Ʈ�� ��ȯ�մϴ�.

Parameters
----------
topic_model
    �ĺ��� ������ ������� ������ �ִ� ���� ���� �ν��Ͻ�
)"");

DOC_SIGNATURE_EN_KO(PMIExtractor___init____doc__,
	"PMIExtractor(min_cf=10, min_df=5, max_len=5, max_cand=5000)",
	u8R""(.. versionadded:: 0.6.0

`PMIExtractor` exploits multivariate pointwise mutual information to extract collocations. 
It finds a string of words that often co-occur statistically.

Parameter
---------
min_cf : int
    minimum collection frequency of collocations. Collocations with a smaller collection frequency than `min_cf` are excluded from the candidates.
    Set this value large if the corpus is big
min_df : int
    minimum document frequency of collocations. Collocations with a smaller document frequency than `min_df` are excluded from the candidates.
    Set this value large if the corpus is big
max_len : int
    maximum length of collocations
max_cand : int
    maximum number of candidates to extract
)"",
	u8R""(.. versionadded:: 0.6.0

`PMIExtractor`�� �ٺ��� ���� ��ȣ�������� Ȱ���� ��� �����մϴ�. �̴� ��������� ���� �Բ� �����ϴ� �ܾ�� ã���ݴϴ�.

Parameter
---------
min_cf : int
    �����Ϸ��� �ĺ��� �ּ� �弭 ��. ���� �� �����ϴ� �󵵼��� `min_cf`���� ���� ����� �ĺ����� ���ܵ˴ϴ�.
    �м��Ϸ��� ���۽��� Ŭ ��� �� ���� Ű��ʽÿ�.
min_df : int
    �����Ϸ��� �ĺ��� �ּ� ���� ��. ��� �����ϴ� ���� ���� `min_df`���� ���� ��� �ĺ����� ���ܵ˴ϴ�.
    �м��Ϸ��� ���۽��� Ŭ ��� �� ���� Ű��ʽÿ�.
max_len : int
    �м��Ϸ��� ������ �ִ� ����
max_cand : int
    �����Ϸ��� �ĺ��� �ִ� ����
)"");

/*
	class FoRelevance
*/
DOC_SIGNATURE_EN_KO(Labeler_get_topic_labels__doc__,
	"get_topic_labels(self, k, top_n=10)",
	u8R""(Return the top-n label candidates for the topic `k`

Parameter
---------
k : int
    an integer indicating a topic
top_n : int
    the number of labels
)"",
	u8R""(���� `k`�� �ش��ϴ� ���̺� �ĺ� ���� n���� ��ȯ�մϴ�.

Parameter
---------
k : int
    ������ �����ϴ� ����
top_n : int
    ���� ���̺��� ����)"");

DOC_SIGNATURE_EN_KO(FoRelevance___init____doc__,
	"FoRelevance(topic_model, cands, min_df=5, smoothing=0.01, mu=0.25, workers=0)",
	u8R""(.. versionadded:: 0.6.0

This type provides an implementation of First-order Relevance for topic labeling based on following papers:

> * Mei, Q., Shen, X., & Zhai, C. (2007, August). Automatic labeling of multinomial topic models. In Proceedings of the 13th ACM SIGKDD international conference on Knowledge discovery and data mining (pp. 490-499).

Parameters
----------
topic_model
    an instance of topic model to label topics
cands : Iterable[tomotopy.label.Candidate]
    a list of candidates to be used as topic labels
min_df : int
    minimum document frequency of collocations. Collocations with a smaller document frequency than `min_df` are excluded from the candidates.
    Set this value large if the corpus is big
smoothing : float
    a small value greater than 0 for Laplace smoothing
mu : float
    a discriminative coefficient. Candidates with high score on a specific topic and with low score on other topics get the higher final score when this value is the larger.
workers : int
    an integer indicating the number of workers to perform samplings. 
    If `workers` is 0, the number of cores in the system will be used.
)"",
	u8R""(.. versionadded:: 0.6.0

First-order Relevance�� �̿��� ���� �󺧸� ����� �����մϴ�. �� ����ü�� ���� ���� �����ϰ� �ֽ��ϴ�:

> * Mei, Q., Shen, X., & Zhai, C. (2007, August). Automatic labeling of multinomial topic models. In Proceedings of the 13th ACM SIGKDD international conference on Knowledge discovery and data mining (pp. 490-499).

Parameters
----------
topic_model
    ���ȸ��� ���� ���� ���� �ν��Ͻ�
cands : Iterable[tomotopy.label.Candidate]
    ���ȸ����� ���� �ĺ����� ����Ʈ
min_df : int
    ����Ϸ��� �ĺ��� �ּ� ���� ��. ��� �����ϴ� ���� ���� `min_cf`���� ���� ��� ���ÿ��� ���ܵ˴ϴ�.
    �м��Ϸ��� ���۽��� Ŭ ��� �� ���� Ű��ʽÿ�.
smoothing : float
    ���ö� ��Ȱȭ�� ���� 0���� ū ���� �Ǽ�
mu : float
    ������ ���. Ư�� ���ȿ� ���ؼ��� ���� ������ ������, ������ ���ȿ� ���ؼ��� ���� ������ ���� �ĺ��� �� ����� Ŭ �� �� ���� ���� ������ �޽��ϴ�.
workers : int
    �齺 ���ø��� �����ϴ� ���� ����� �������� �����Դϴ�. 
    ���� �� ���� 0���� ������ ��� �ý��� ���� ������ ��� �ھ ���˴ϴ�.
)"");
